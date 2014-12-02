#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include "edge.h"
#include "vertex.h"
#include <QString>
#include <iostream>
#include <QFile>
#include <QList>

using namespace std;

class Graph{

private:
    int edgeCounter;
    int vertexCounter;
    QList< QList<vertex*> > vertexList;
    QString readListFile(QString filename);//открывает файл что содержит список
    int getMaxVertex(QStringList vertex_pairs);//получает количество вершин
public:
    Graph();
    ~Graph();
    void weightMatrixInit(); //выделение памяти под матрицу весов при необходимости
    void initVertexList();   //создание массивa вершин
    void cleanMemory();      //очищение памяти от существующих массивов
    void calcPositions();
    bool BFS(int startVertex, int finishVertex, QList<int>* visitedVertex);
    void DFS(int vertex1,int vertex2,QList<int>* vertexes);
    void OpenFileWithGraph(QString filename);
    bool compare_graphs(QString path1, QString path2);
    int getVertexCount();
    int getEdgeCount();
    QList < QList<vertex*> > getVertexList(){return vertexList;}
    vertex getVertex(int i, int j){return *vertexList[i][j];}
    bool operator ==(Graph to_compare);
    void throwPaint();

    void setGraphFromVK(int uid, QList<vertex*> friends);
};

#endif
