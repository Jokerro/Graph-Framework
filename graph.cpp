#include "graph.h"

#include <iostream>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDataStream>
#include <QFile>
#include <vector>
#include <QQueue>
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

bool isInside(vector<int> arr, int v)
{
    for(int i=0;i<arr.size();i++)
        if(v==arr[i])
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

void Graph::DFS(int vertex1, int vertex2)
{///!!!!!///ДОБАВИТЬ ПРОВЕРКУ, ЕСЛИ ИЗОЛИРОВАННАЯ ВЕРШИНА ВЫБРАНА!

    vector<int> vertexes;  //вершины, по которым поиск будет идти
    vertexes.push_back(vertex1);

    while(vertexes[vertexes.size()-1]!=vertex2)
    {
        //DepthSearchStep(this,vertexes,vertex2);
        //смежна ли последняя концу?
        bool Endfound=false;
        for(int i=0;i<this->vertexList[vertexes[vertexes.size()-1]].size();i++)
        {
            if(this->vertexList[vertexes[vertexes.size()-1]][i]->GetId()==vertex2)
            {
                vertexes.push_back(vertex2);
                Endfound=true;
                break;
            }
        }
        if(Endfound)
            break;
        //поиск смежных непройденных
        bool hasNew=false;
        for(int i=0;i<this->vertexList[vertexes[vertexes.size()-1]].size();i++)
        {
            if(!isInside(vertexes,this->vertexList[vertexes[vertexes.size()-1]][i]->GetId()))
            {
                hasNew=true;
                vertexes.push_back(this->vertexList[vertexes[vertexes.size()-1]][i]->GetId());
                break;
            }
        }
        //нет смежных вершин. то, что сюда не дойдем, если смежные непройденные есть - понятно, но чтобы проще понимать - булевую переменную оставляю
        if(!hasNew)
        {
            vertexes.push_back(vertexes[vertexes.size()-2]);
            continue;
        }
    }
    int a=0;
}

