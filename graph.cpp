#include "graph.h"
<<<<<<< HEAD
=======
#include <iostream>
#include <QString>
#include <QStringList>
#include <QFile>
>>>>>>> 0a90d2fee698eb6bb1c3e592f24a6e1a94331966

Graph::Graph()
{
    vertexCounter=0;
    edgeCounter=0;
    weightMatrix = NULL;
    incidenceMatrix = NULL;
    adjacensyMatrix = NULL;

}

Graph::~Graph() {}

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
        QStringList vertex = QString(vertex_pairs[i]).split(",");//разделение пары на отдельные вершиы
        for(int j=0; j<vertex.length(); j++){
            if (vertex[j].toInt()>max){
                max=vertex[j].toInt();
            }
        }
    }
    return max;
}

QStringList Graph::stringToList(QString temp){
    QStringList vertex_pairs = temp.split("},{");//разрезание на пары вершин
    //обрезка лишних символов
    for(int i=0; i< vertex_pairs.length(); i++){
        vertex_pairs[i].replace("{","\0");
        vertex_pairs[i].replace("},","\0");
        vertex_pairs[i].replace("}.","\0");
        vertex_pairs[i].replace("}","\0");
    }
   return vertex_pairs;
}

void Graph::getFromListToMatrix(QString filename){
  //получает готовые пары вершин
  QStringList vertex_pairs = stringToList(readListFile(filename));
  int n=getMaxVertex(vertex_pairs);
  //выдиление памяти под строки  матрицы инцедентности
  adjacensyMatrix= new int*[n];

  for(int i=0; i<n; i++){
      //выдиление памяти под столбцы  матрицы инцедентности
     adjacensyMatrix[i] = new int[n];
      for(int j=0; j<n; j++){
          //инициализация
        adjacensyMatrix[i][j]=0;

        for(int index= 0; index<vertex_pairs.length(); index++) {
            //нарезка пар на вершины
          QStringList vertex = QString(vertex_pairs[index]).split(",");
           //заполнение
          if((vertex[0].toInt()-1==i) &&(vertex[1].toInt()-1==j)){
            adjacensyMatrix[i][j]=1;
          }
        }
      }
  }
    //для неориентированого графа
  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         adjacensyMatrix[j][i]=adjacensyMatrix[i][j];
       }
  }
}

bool Graph::compare_graphs(QString path1, QString path2)
{
   QFile graph1(path1);
   QFile graph2(path2);
}

int Graph::getVertexCount(){
    return vertexCounter;
}

int Graph::getEdgeCount(){
    return edgeCounter;
}

<<<<<<< HEAD
int Graph::getAdjecensyMatrix(int i, int j){
    return adjacensyMatrix[i][j];
}

=======
>>>>>>> 0a90d2fee698eb6bb1c3e592f24a6e1a94331966
