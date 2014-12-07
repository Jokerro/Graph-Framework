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
}

Graph::~Graph() {
    cleanMemory();
}

void Graph::cleanMemory(){
   for(int i=0; i<vertexList.length(); i++)
       vertexList.removeAt(i);
   vertexList.clear();
}

void Graph::calcPositions(){
    srand(12);
    int rightBorder=vertexList.length()*25;
    int bottomBorder=vertexList.length()*25;
    for(int i=0; i<vertexList.length(); i++)
        vertexList[i][0]->setPosition(rand()%rightBorder+5, rand()%bottomBorder+5);

}

void Graph::throwPaint(){
    for(int i=0; i<vertexList.length(); i++)
        for(int j=0; j<vertexList[i].length(); j++)
            vertexList[i][j]->noPaint();
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
                 tempVertexList.push_back(new vertex(list[0].toInt()));
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
                        if(list.length()>1 && list[1]!="" && list[1]!="\n")
                            temp1.push_back(tempVertexList[list[1].toInt()-1]);
                        curr=list[0].toInt();
                        flag=1;
                 }else{
                     if(list.length()>1&& list[1]!="")
                        temp1.push_back(tempVertexList[list[1].toInt()-1]);
                 }

            }vertexList.push_back(temp1);
        }
        tempVertexList.clear();
  }

bool Graph::BFS(int startVertex, int finishVertex, QList<int>* visitedVertex){

    QQueue<int> vertexQueue;
    vector<int> p(vertexList.length());

    vertexQueue.enqueue(startVertex);
    visitedVertex->push_back(startVertex);
    p[startVertex]=-1;

    while(!vertexQueue.isEmpty()){

        int node= vertexQueue.dequeue();

        if(node==finishVertex){
            visitedVertex->clear();
             for (int v=finishVertex; v!=-1; v=p[v]){
                    visitedVertex->push_front (v);
            }
            p.clear();
            return true;
        }

        for(int i=0; i< vertexList.length(); i++ ){
            if(vertexList[i].length()>1){
                if(vertexList[i][0]->GetId()==node){
                    for(int j=1; j<vertexList[i].length(); j++){

                        if(visitedVertex->indexOf(vertexList[i][j]->GetId())==-1){
                            vertexQueue.enqueue(vertexList[i][j]->GetId());
                            visitedVertex->push_back(vertexList[i][j]->GetId());
                            p[vertexList[i][j]->GetId()] = node;
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

void Graph::DFS(int vertex1, int vertex2,QList<int>* vertexes)
{///!!!!!///ДОБАВИТЬ ПРОВЕРКУ, ЕСЛИ ИЗОЛИРОВАННАЯ ВЕРШИНА ВЫБРАНА!

    vertexes->push_back(vertex1);

    while(vertexes->at(vertexes->length()-1)!=vertex2)
    {
        //DepthSearchStep(this,vertexes,vertex2);
        //смежна ли последняя концу?
        bool Endfound=false;
        for(int i=1;i<this->vertexList[(vertexes->at(vertexes->length()-1)-1)].size();i++)
        {
            if(this->vertexList[(vertexes->at(vertexes->size()-1))-1][i]->GetId()==vertex2)
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
        for(int i=1;i<this->vertexList[(vertexes->at(vertexes->length()-1))-1].size();i++)
        {
            if(!isInside(vertexes,this->vertexList[(vertexes->at(vertexes->length()-1))-1][i]->GetId()))
            {
                hasNew=true;
                vertexes->push_back(this->vertexList[(vertexes->at(vertexes->length()-1))-1][i]->GetId());
                break;
            }
        }
        //нет смежных вершин. то, что сюда не дойдем, если смежные непройденные есть - понятно, но чтобы проще понимать - булевую переменную оставляю
        if(!hasNew)
        {
            vertexes->push_back(vertexes->at(vertexes->length()-2));
            continue;
        }
    }
    int a=0;
}



void Graph::setGraphFromVK(int uid, QList<int> friends)
{
    QList<vertex*> tempVertexList;

    bool flag = false;
    for (int i = 0; i< vertexList.size(); i++)
        if (friends[0] == vertexList[i].at(0)->GetId()){
            flag = true;
            tempVertexList.append(vertexList[i].at(0));
            vertexList.removeAt(i);
            break;
        }
    if (!flag){
        tempVertexList.append(new vertex(friends[0], new Node(widget)));
        widget->scene()->addItem(tempVertexList[0]->getNode());
    }
    for (int i = 1; i< friends.size(); i++){
        bool flag = false;
        for (int j = 0; j< vertexList.size(); j++)
        if (friends[i] == vertexList[j].at(0)->GetId()){
            flag=true;
            tempVertexList.append(vertexList[j].at(0));
            break;
        }
        if (!flag){
            QList<vertex*> temp1;
            temp1.append(new vertex(friends[i], new Node(widget)));
            vertexList.append(temp1);
            tempVertexList.append(temp1[0]);
            temp1.clear();
            widget->scene()->addItem(tempVertexList[tempVertexList.size()-1]->getNode());
            tempVertexList[tempVertexList.size()-1]->getNode()->setPos(i,i*5);
        }
        widget->scene()->addItem(
                    new Edge(tempVertexList[0]->getNode(), tempVertexList[tempVertexList.size()-1]->getNode()));


    }
    qDebug()<<vertexList.size();
    this->calcPositions();
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
