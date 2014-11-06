#include "graph.h"

#include <iostream>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDataStream>
#include <QFile>


Graph::Graph()
{
    vertexCounter=0;
    edgeCounter=0;
    weightMatrix = NULL;
    incidenceMatrix = NULL;
    adjacensyMatrix = NULL;
}

Graph::~Graph() {
    cleanMemory();
}

void Graph::initAdjacensy(int i_VCount){
     vertexCounter=i_VCount;
     adjacensyMatrix=new int* [vertexCounter];
     for (int i=0; i<vertexCounter; i++)
     {
         adjacensyMatrix[i]=new int[vertexCounter];
     }
}
void Graph::initIncidence(int i_ECount)
{
    edgeCounter=i_ECount;
    incidenceMatrix=new int* [vertexCounter];
    for(int i=0; i<vertexCounter; i++)
    {
        incidenceMatrix[i]=new int[edgeCounter];
    }
}

void Graph::initVertexList()
{
        for(int i=0; i<vertexCounter; i++)
        {
            int i_deg=0;
            for(int j=0; j<vertexCounter; j++)
                i_deg+=adjacensyMatrix[i][j];
            vertex Temp(i, i_deg);
            Vertexes.append(Temp);
       }
}

//    for(int i=0; i<vertexCounter; i++)
//    {
//        int i_deg=0;
//        for(int j=0; j<vertexCounter; j++)      этот кусок кода выполднить в отдельной функции после заполнения матрицы значениями
//            i_deg+=adjacensyMatrix[i][j];
//        vertex Temp=new vertex(i, i_deg);
//        Vertexes.append(Temp);
//    }

void Graph::weightMatrixInit()
{
    weightMatrix=new int*[vertexCounter];
    for (int i=0; i<vertexCounter; i++)
    {
        weightMatrix[i]=new int[vertexCounter];
    }
}

void Graph::cleanMemory(){
    if(adjacensyMatrix!=NULL)
    {
        for(int i=0; i<vertexCounter; i++)
            delete [] adjacensyMatrix[i];
        delete[] adjacensyMatrix;
    }
    if(incidenceMatrix!=NULL)
    {
        for(int i=0; i<vertexCounter; i++)
            delete [] incidenceMatrix[i];
        delete[] incidenceMatrix;
    }
    if(weightMatrix!=NULL)
    {
        for(int i=0; i<vertexCounter; i++)
            delete [] weightMatrix[i];
        delete [] weightMatrix;
    }
    weightMatrix = NULL;
    incidenceMatrix = NULL;
    adjacensyMatrix = NULL;
    for (int i = Vertexes.length()-1; i>=0; i--)
        Vertexes.remove(i);
    for (int i = Edges.length()-1; i>=0; i--)
        Edges.remove(i);
}

QString Graph::readListFile(QString filename)//считывание файла в строку
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

int Graph::getVertexCount(){
    return vertexCounter;
}

int Graph::getEdgeCount(){
    return edgeCounter;
}

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

