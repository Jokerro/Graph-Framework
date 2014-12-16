#include "graph.h"

#include <iostream>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDataStream>
#include <QFile>
#include <vector>
#include <QQueue>
#include <QDebug>

Graph::Graph()
{
    vertexCounter=0;
    edgeCounter=0;
    //main_users_indexes = new QList<int>();
}

Graph::~Graph() {
    cleanMemory();
}

void Graph::setChoosed(int f)
{
    qDebug()<<f;
    if(Graph::first_selected==0)
        Graph::first_selected=f;
    else if(Graph::second_selected==0)
        Graph::second_selected=f;
}

vertex* Graph::checkVertex(int id){

    for (int i = 0; i < vertexList.size(); i++)
        if (vertexList[i][0]->GetId() == id)
            return vertexList[i][0];
    return NULL;

}


void Graph::cleanMemory(){
   for(int i=0; i<vertexList.length(); i++)
       vertexList.removeAt(i);
   vertexList.clear();
}


int Graph::getVertexCount(){
    return vertexCounter;
}

int Graph::getEdgeCount(){
    return edgeCounter;
}

bool isInside(QList<int>* arr, int v)
{
    for(int i=0;i<arr->length();i++)
        if(v==arr->at(i))
            return true;
    return false;
}




void Graph::OpenFileWithGraph(QString filename)
{
    int prev=-1, curr=-1, flag=0;
    QList<vertex*> tempVertexList;
    QList<vertex*> temp1;
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly |QIODevice::Text))
    {
        while(!file.atEnd())
        {

             QString str = file.readLine();
             if(str[0] == '#')
                  continue;
             QStringList list = str.split("\t");
             if(prev!=list[0].toInt())
                 tempVertexList.push_back(new vertex(list[0].toInt(), new Node(widget)));
             prev=list[0].toInt();
        }
    }
        file.close();
        if(file.open(QIODevice::ReadOnly |QIODevice::Text))
        {
            while(!file.atEnd())
            {
                 QString str = file.readLine();
                 if(str[0] == '#')
                      continue;
                 QStringList list = str.split("\t");
                 if(list[0].toInt()!=curr)
                 {
                        if(flag==1)
                        {
                            vertexList.push_back(temp1);
                            temp1.clear();
                        }
                        temp1.push_back(tempVertexList[list[0].toInt()-1]);
                        if(list.length()>1 && list[1]!="" && list[1]!="\n"){
                            temp1.push_back(tempVertexList[list[1].toInt()-1]);
                            widget->scene()->addItem(
                                        new Edge(tempVertexList[list[1].toInt()-1]->getNode(),
                                                tempVertexList[list[0].toInt()-1]->getNode()));
                            edgeCounter++;
                            tempVertexList[list[0].toInt()-1]->getNode()->edges().at(tempVertexList[list[0].toInt()-1]->getNode()->edges().size()-1)->setZValue(-99999);

                        }
                        curr=list[0].toInt();
                        flag=1;
                 }else{
                     if(list.length()>1&& list[1]!="")
                        temp1.push_back(tempVertexList[list[1].toInt()-1]);
                     widget->scene()->addItem(
                                 new Edge(tempVertexList[list[1].toInt()-1]->getNode(),
                                         tempVertexList[list[0].toInt()-1]->getNode()));
                     edgeCounter++;
                     tempVertexList[list[0].toInt()-1]->getNode()->edges().at(tempVertexList[list[0].toInt()-1]->getNode()->edges().size()-1)->setZValue(-99999);
                 }

            }vertexList.push_back(temp1);
        }

        tempVertexList.clear();
        for(int i=0;i<this->vertexList.size();i++){
            vertexList[i][0]->setID(i+1);
            vertexList[i][0]->getNode()->setPos(i,i*5);
            widget->scene()->addItem(vertexList[i][0]->getNode());
        }
        vertexCounter = vertexList.size();
}

bool Graph::BFS(int startVertex, int finishVertex, QList<int>* visitedVertex){

    QQueue<int> vertexQueue;
    vector<int> p(vertexList.length());

    //Индексы
    QList<int>*v=new QList<int>;
    int finishVertex_iterator;

    for(int i=0;i<vertexList.size();i++){
         if(vertexList[i][0]->GetUserId()==startVertex)
            v->push_back(vertexList[i][0]->GetId()-1);
         if(vertexList[i][0]->GetUserId()==finishVertex)
         { finishVertex_iterator=vertexList[i][0]->GetId()-1;}
    }


    vertexQueue.enqueue(startVertex);
    visitedVertex->push_back(startVertex);
    p[v->at(0)]=-1;

    while(!vertexQueue.isEmpty()){

        int node= vertexQueue.dequeue();

        if(node==finishVertex){
            visitedVertex->clear();
             for (int l=finishVertex_iterator; l!=-1; l=p[l]){
                    visitedVertex->push_front (vertexList[l][0]->GetUserId());
            }
            p.clear();
            return true;
        }

        for(int i=0; i< vertexList.length(); i++ ){
            if(vertexList[i].length()>1){
                if(vertexList[i][0]->GetUserId()==node){
                    for(int j=1; j<vertexList[i].length(); j++){

                        if(visitedVertex->indexOf(vertexList[i][j]->GetUserId())==-1){
                            vertexQueue.enqueue(vertexList[i][j]->GetUserId());
                            visitedVertex->push_back(vertexList[i][j]->GetUserId());
                            v->push_back(vertexList[i][j]->GetId()-1);
                            p[vertexList[i][j]->GetId()-1] = vertexList[i][0]->GetId()-1;
                        }
                    }
                    break;
                }
            }
        }
    }
    visitedVertex->clear();
    return false;
}


int Graph::getIndex(int id)
{
    for(int i=0;i<vertexList.size();i++)
        if(vertexList[i][0]->GetId()==id)
            return i;
    return 0;
}


void Graph::minimum_cuts(QList<Node *> *res)
{QList<Edge*> temp;
    for(int i=0;i<main_users_indexes.length();i++)
    {
        temp.push_back(vertexList[main_users_indexes[i]][0]->getNode()->edges().at(0));
        for(int j=1;j<vertexList[main_users_indexes[i]][0]->getNode()->edges().length();j++)
        {
            if(vertexList[main_users_indexes[i]][0]->getNode()->edges().at(j)->getWeight()<temp.at(temp.size()-1)->getWeight())
            {
                temp.clear();
                temp.push_back(vertexList[main_users_indexes[i]][0]->getNode()->edges().at(j));
            }
            else if (vertexList[main_users_indexes[i]][0]->getNode()->edges().at(j)->getWeight() == temp.at(temp.size()-1)->getWeight())
                 temp.push_back(vertexList[main_users_indexes[i]][0]->getNode()->edges().at(j));
        }

        for(int j=0;j<temp.size();j++){
            if(temp.at(j)->destNode()->getTrueId()!=vertexList[main_users_indexes[0]][0]->GetUserId())
                res->push_back(temp.at(j)->destNode());
        }
    }


}

void Graph::DFS(int vertex1, int vertex2,QList<int>* vertexes)
{///!!!!!///ДОБАВИТЬ ПРОВЕРКУ, ЕСЛИ ИЗОЛИРОВАННАЯ ВЕРШИНА ВЫБРАНА!

    //Индексы
    QList<int>*v=new QList<int>;

    for(int i=0;i<vertexList.size();i++)
        if(vertexList[i][0]->GetUserId()==vertex1)
           v->push_back(vertexList[i][0]->GetId());

    vertexes->push_back(vertex1);

    while((vertexes->at(v->length()-1))!=vertex2)
    {
        //смежна ли последняя концу?
        bool Endfound=false;

        for(int i=1;i<this->vertexList[getIndex(v->at(v->size()-1))].size();i++)
        {
            if(this->vertexList[getIndex(v->at(v->size()-1))][i]->GetUserId()==vertex2)
            {
                vertexes->push_back(vertex2);
                Endfound=true;
                break;
            }
        }
        if(Endfound)
            break;
        //поиск смежных непройденных
        bool hasNew=false;

        for(int i=1;i<this->vertexList[ getIndex(v->at(v->size()-1)) ].size();i++)
        {
            if(!isInside(vertexes,this->vertexList[getIndex(v->at(v->size()-1))][i]->GetUserId()))
            {
                hasNew=true;
                vertexes->push_back(this->vertexList[getIndex(v->at(v->size()-1))][i]->GetUserId());
                v->push_back(this->vertexList[getIndex(v->at(v->size()-1))][i]->GetId());

                break;
            }
        }
        //нет смежных вершин. то, что сюда не дойдем, если смежные непройденные есть - понятно, но чтобы проще понимать - булевую переменную оставляю
        if(!hasNew)
        {
            vertexes->push_back(vertexes->at(v->length()-2));
            v->push_back(v->at(v->length()-2));
                        continue;
        }
    }
}

bool Graph::saveGraph(QString path){

    QFile* file = new QFile(path);
    if (file->open(QIODevice::WriteOnly | QIODevice::Text)){

        QTextStream out(file);

        for (int i = 0; i<vertexList.size(); i++)
            if (vertexList[i].size()>=2)
                for (int j = 1; j<vertexList[i].size(); j++)
                    out << vertexList[i][0]->GetId() << "\t" << vertexList[i][j]->GetId() << "\n";
            else
                out << vertexList[i][0]->GetId() << "\n";

        file->close();

        return true;

    }else{

        return false;

    }

}


void Graph::addVertexFromVK(VKResponse user){

    QImage img;
    bool flag = false;
    for (int i=0; i<vertexList.size(); i++){
        if(vertexList[i][0]->GetUserId() == user.id){
            flag=true;
            break;
        }
    }
    if(!flag){
        QList<vertex*> tempVertexList;
        tempVertexList.append(new vertex(user, new Node(widget)));
        if(tempVertexList[0]->getCity()!="")
            widget->geoLocation->addGeotoDetect(tempVertexList[0]);
        else
            tempVertexList[0]->SetCoords(0,0);
        if(!img.load("images/"+QString::number(tempVertexList[0]->GetUserId())+".jpg"))
            widget->imgDownloader->addImagetoDownload(tempVertexList[0]);
        else
            tempVertexList[0]->getNode()->setImagePhoto(img);
        widget->scene()->addItem(tempVertexList[0]->getNode());
        vertexList.append(tempVertexList);
    }

}
void Graph::correct(int index)
{
    for(int i=0;i<main_users_indexes.size();i++){
        if(main_users_indexes.at(i)>index)//?main_users_indexes->at(i)--:;
            main_users_indexes[i]--;
    }

}

void Graph::resetGraph()
{
    for(int i=0;i<main_users_indexes.size();i++)
        for(int j=0;j<vertexList.at(main_users_indexes[i]).size();j++)
            vertexList[main_users_indexes[i]][j]->getNode()->resetEdges();
}

void Graph::setGraphFromVK(QList<VKResponse> friends)
{
    QList<vertex*> tempVertexList;
    QImage img;

    bool flag = false;

    for (int i = 0; i< vertexList.size(); i++)
        if (friends[0].id == vertexList[i].at(0)->GetUserId()){qDebug()<<"Oyes";
            flag = true;
            tempVertexList.append(vertexList[i].at(0));
            vertexList.removeAt(i);
            if(i<vertexList.size()-1)
                correct(i);
            if (tempVertexList[0]->getCity() == ""){
                int i = 1;
                while (friends[i].city == "")
                    if (i < friends.size())
                        i++;
                tempVertexList[0]->setCity(friends[i].city);
                widget->geoLocation->addGeotoDetect(tempVertexList[0]);
            }
            break;
        }
    if (!flag){
        tempVertexList.append(new vertex(friends[0], new Node(widget)));
        if(tempVertexList[0]->getCity()!="")
            widget->geoLocation->addGeotoDetect(tempVertexList[0]);
        else
            tempVertexList[0]->SetCoords(0,0);
        if(!img.load("images/"+QString::number(tempVertexList[0]->GetUserId())+".jpg"))
            widget->imgDownloader->addImagetoDownload(tempVertexList[0]);
        else
            tempVertexList[0]->getNode()->setImagePhoto(img);
        widget->scene()->addItem(tempVertexList[0]->getNode());
        tempVertexList[0]->setID(vertexList.size()+1);
    }
    for (int i = 1; i<friends.size(); i++){
        bool flag = false;
        for (int j = 0; j< vertexList.size(); j++)
        if (friends[i].id == vertexList[j].at(0)->GetUserId()){
            flag=true;
            tempVertexList.append(vertexList[j].at(0));
            bool isInside=false;
            for(int temp=0; temp<vertexList[j].size();temp++)
                if(vertexList[j].at(temp)==tempVertexList[0]){
                    isInside = true;
                    break;
                }
            if(!isInside){
                vertexList[j].append(tempVertexList[0]);
            }
            break;
        }
        if (!flag){
            QList<vertex*> temp1;
            temp1.append(new vertex(friends[i], new Node(widget)));
            if(temp1[0]->getCity()!="")
                widget->geoLocation->addGeotoDetect(temp1[0]);
            else
                temp1[0]->SetCoords(0,0);
            if(!img.load("images/"+QString::number(temp1[0]->GetUserId())+".jpg"))
                widget->imgDownloader->addImagetoDownload(temp1[0]);
            else
                temp1[0]->getNode()->setImagePhoto(img);

            temp1.append(tempVertexList[0]);
            vertexList.append(temp1);
            tempVertexList.append(temp1[0]);
            temp1.clear();
            widget->scene()->addItem(tempVertexList[tempVertexList.size()-1]->getNode());
            tempVertexList[tempVertexList.size()-1]->getNode()->setPos(i,i*5);
        }
        widget->scene()->addItem(
                    new Edge(tempVertexList[0]->getNode(), tempVertexList[tempVertexList.size()-1]->getNode()));
        edgeCounter++;

        tempVertexList[0]->getNode()->edges().at(tempVertexList[0]->getNode()->edges().size()-1)->setZValue(-99999);

    }
    vertexList.append(tempVertexList);

    for(int i=0;i<this->vertexList.size();i++)
        vertexList[i][0]->setID(i+1);
    vertexCounter = vertexList.size();
    main_users_indexes.push_back(this->vertexList.size()-1);

}


void Graph::transposeGraph(QList<QList<int> >* resultGraph){
    QList<int> marked;
    for(int i=0; i<vertexList.length(); i++){
        for(int j=1; j<vertexList[i].length(); j++){
            if(marked.indexOf(vertexList[i][j]->GetId())==-1){
                marked.push_back(vertexList[i][j]->GetId());
                QList<int> tempList;
                tempList.push_back(vertexList[i][j]->GetId());
                tempList.push_back(vertexList[i][0]->GetId());
                resultGraph->push_back(tempList);
            }else{
               for(int k=0; k<resultGraph->length(); k++){
                   if(resultGraph->at(k)[0]==vertexList[i][j]->GetId())
                     resultGraph->operator [](k).push_back(vertexList[i][0]->GetId());
               }
            }
        }
    }
   marked.clear();
}

void Graph::strongComponentDFS(int v) {
    used.push_back(v);
    for(int i=0; i<vertexList.length(); i++){
       if (vertexList[i].at(0)->GetId()==v){
           if (vertexList[i].size()>1){
            for (int j=1; j<vertexList[i].size(); ++j)
            {
                if (used.indexOf(vertexList[i].at(j)->GetId())==-1)
                    strongComponentDFS( vertexList[i].at(j)->GetId());
            }
           }
       }
    }
    order.push_back (v);
}

void Graph::transposedGraphDFS(int v, QList<QList<int> >* transposedGraph, QList<int>* component) {
    used.push_back(v);
    component->push_back(v);
    for(int i=0; i<transposedGraph->length(); i++){
       if (transposedGraph->at(i).at(0)==v){
           if (transposedGraph->at(i).size()>1){
            for (int j=1; j<transposedGraph->at(i).size(); ++j) {
                if (used.indexOf(transposedGraph->at(i).at(j))==-1)
                    transposedGraphDFS(transposedGraph->at(i).at(j), transposedGraph, component);
            }
           }
       }
    }
}

void Graph::getStrongComponents(QList<QList<int> >* components) {
    QList<QList<int> > t;
    QList<int> component;
    transposeGraph(&t);

    for(int i=0; i<vertexList.length(); i++)
        if(used.indexOf(vertexList[i][0]->GetId())==-1)
            strongComponentDFS(vertexList[i][0]->GetId());

    used.clear();
    for(int i=0; i<vertexList.length(); i++){
        int v = order[vertexList.length()-1-i];
        if(used.indexOf(v)==-1){
            component.clear();
            transposedGraphDFS(v, &t, &component);
            components->append(component);
        }
    }
}

void Graph::dfsTopo(int cur, QList<vertex*>* ans) {
    used_topo[cur] = GRAY;
    for (int i=1; i<vertexList[cur].size(); i++) {
        int next = vertexList[cur][i]->GetId()-1;
        // if (used_topo[next] == GRAY) // Circle
        if (used_topo[next] == WHITE)
            dfsTopo(next,ans);
    }
    used_topo[cur] = BLACK;
    ans->append(vertexList[cur][0]);
}

void Graph::topoRecur(QList<vertex*>* ans) {
    for (int i=0;i<vertexCounter;i++) {
        if (used_topo[i] == WHITE) {
            dfsTopo(i,ans);
        }
    }
}

void Graph::topoSort(){
    used_topo.resize(vertexCounter,WHITE);
    QList<vertex*> ans;
    topoRecur(&ans);
    for (int i=vertexCounter-1;i >= 0;i--)
        ans[i]->setID(vertexCounter-i);

}
int Graph::getEdgeWeigth(int v, int u){
    for(int j=0; j<vertexList.length(); j++){
        if(v==vertexList[j][0]->GetUserId())
        for(int k=0; k<vertexList[j][0]->getNode()->get_edges().length();k++){
           if (vertexList[j][0]->getNode()->get_edges()[k]->destNode()->getTrueId()==u){
                    return vertexList[j][0]->getNode()->get_edges()[k]->getWeight();
            }
        }
    }
   return -1;
}

void Graph::getShortestPath(int vertex1, int vertex2){
    int v;
    int infinity = 100000000000;
    QMap<int, int> t;
    QMap<int, int> x;
    QMap<int, int> h;
    for(int i=0; i<vertexList.length(); i++){
        int u=vertexList[i][0]->GetUserId();
        t.insert(u,infinity);
        x.insert(u,0);
    }

    h.insert(vertex1,0);
    t.insert(vertex1,0);
    x.insert(vertex1, 1);
    v=vertex1;

    while(1){
        for(int i=0; i<vertexList.length(); i++){
            int u=vertexList[i][0]->GetUserId();
            int weigth=getEdgeWeigth(v, u);
            if (weigth>=0)
               if (x[u]==0 && t[u]>t[v]+weigth){
                t[u]=t[v]+weigth;
                h[u]=v;
            }
        }

        int w=infinity;
        v=-1;
        for(int i=0; i<vertexList.length(); i++){
                int u=vertexList[i][0]->GetUserId();
                if(x[u]==0 && t[u]<w){
                    v=u;
                    w=t[u];
                }
        }

        if(v==-1){
             std::cout<<"Not found";
            break;
        }
        if(v==vertex2){
            int u=vertex2;
            while(u!=vertex1){
                std::cout<<"  "<<u;
                u=h[u];
            }
            break;
        }
        x[v]=1;
    }
}
