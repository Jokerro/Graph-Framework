#include "graph.h"

#include <iostream>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDataStream>
#include <QFile>
#include <vector>

Graph::Graph()
{
    vertexCounter=0;
    edgeCounter=0;
    //weightMatrix = NULL;
    //incidenceMatrix = NULL;
    //adjacensyMatrix = NULL;
}

Graph::~Graph() {
    cleanMemory();
}

void Graph::cleanMemory(){
   for(int i=0; i<vertexList.length(); i++)
       vertexList.removeAt(i);
   vertexList.clear();
}

/*QString Graph::readListFile(QString filename)//считывание файла в строку
{
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return NULL;
        QByteArray total;
        QByteArray line;
        while (!file.atEnd()) {
           line = file.read(1024);
           total.append(line);
        }
        return QString(total);
}

int Graph::getMaxVertex(QStringList vertex_pairs){ //определяет количество вершин
    int max=0;
    for(int i=0; i<vertex_pairs.length(); i++){
        QStringList vertex = QString(vertex_pairs[i]).split(",");//разделение на отдельные вершиы
        QStringList main= QString(vertex[0]).split(":");//получение ведущей вершины
        vertex.insert(vertex.length(), main[0]);
        vertex.insert(vertex.length(), main[1]);
        for(int j=1; j<vertex.length(); j++){
            if (vertex[j].toInt()>max){
                max=vertex[j].toInt();
            }
        }
    }
    return max;
}


void Graph::getFromListToMatrix(QString filename){
  //получает готовые пары вершин
  QStringList linked_vertexes = readListFile(filename).split(";");
  cleanMemory();
  initAdjacensy(getMaxVertex(linked_vertexes));//matrix initialization
  for(int i=0; i<linked_vertexes.length(); i++){
     QStringList main_vertexs = QString(linked_vertexes[i]).split(":");//get basic vertex
     QStringList sub_vertexs = QString(main_vertexs[1]).split(","); //get other vertex
     if(sub_vertexs[0]!=""){
        for(int j=0; j<sub_vertexs.length(); j++){
            adjacensyMatrix[main_vertexs[0].toInt()-1][sub_vertexs[j].toInt()-1]=1;
            edgeCounter+=1;
            adjacensyMatrix[sub_vertexs[j].toInt()-1][main_vertexs[0].toInt()-1]=1;
        }
     }
  }
  QTextStream cout(stdout);
  for(int i=0; i<vertexCounter; i++){
      for(int j=0; j<vertexCounter; j++){
        cout<< adjacensyMatrix[i][j];
      }
      cout<< endl;
  }
}

bool Graph::compare_graphs(QString path1, QString path2)
{
   QFile graph1(path1);
   QFile graph2(path2);

   return false;
}
*/
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

void DepthSearchStep(Graph* g,vector<int> vertexes,int endV)
{
    //смежна ли последняя концу?
    for(int i=0;i<g->vertexList.at(vertexes[vertexes.size()-1]).size();i++)
    {
        if(g->vertexList[vertexes[vertexes.size()-1]][i].GetId()==endV)
        {
            vertexes.push_back(endV);
            return;
        }
    }
    //поиск смежных непройденных
    bool hasNew=false;
    for(int i=0;i<g->vertexList[vertexes[vertexes.size()-1]].size();i++)
    {
        if(!isInside(vertexes,g->vertexList[vertexes[vertexes.size()-1]][i].GetId()))
            hasNew=true;
        vertexes.push_back(g->vertexList[vertexes[vertexes.size()-1]][i].GetId());
        return;
    }
    //нет смежных вершин. то, что сюда не дойдем, если смежные непройденные есть - понятно, но чтобы проще понимать - булевую переменную оставляю
    if(!hasNew)
    {
        vertexes.push_back(vertexes[vertexes.size()-2]);
        return;
    }
}

void Graph::DFS(int vertex1, int vertex2)
{///!!!!!///ДОБАВИТЬ ПРОВЕРКУ, ЕСЛИ ИЗОЛИРОВАННАЯ ВЕРШИНА ВЫБРАНА!
    vector<int> vertexes;  //вершины, по которым поиск будет идти
    vertexes.push_back(vertex1);

    while(vertexes[vertexes.size()-1]!=vertex2)
    {
        DepthSearchStep(this,vertexes,vertex2); \
    }
}

/*
int Graph::getAdjecensyMatrixElem(int i, int j){
    return adjacensyMatrix[i][j];
}

void Graph::ReadMatrix(QString path){
    QStringList columns = readListFile(path).split("\n");
    vertexCounter = columns[0].toInt();
    cleanMemory();
    initAdjacensy(vertexCounter);
    int k=0;
    for (int i = 0; i < vertexCounter; ++i) {
        QStringList rows= QString(columns[i+1]).split(",");
        for (int j = 0; j < vertexCounter; ++j) {
             adjacensyMatrix[i][j]=rows[j].toInt();
             if(j-i>=0)
                edgeCounter+=adjacensyMatrix[i][j+k];
        }
    }
    QTextStream cout(stdout);
    cout << edgeCounter << "\n" << endl;
}

bool Graph::operator ==(Graph to_compare)
{
    if(this->edgeCounter!=to_compare.edgeCounter)
        return false;

    for(int i=0;i<this->edgeCounter;i++)
        for(int j=0;j<this->edgeCounter;j++)
            if(this->adjacensyMatrix[i][j]!=to_compare.adjacensyMatrix[i][j])
                return false;

    return true;
}
*/
