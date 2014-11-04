#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <vector>
#include "edge.h"
#include "vertex.h"
#include <QString>
#include <iostream>
#include <QFile>

using namespace std;

class Graph{

private:
    vector <vertex> Vertexes;
    vector <edge> Edges;
    int** adjacensyMatrix;
    int** incidenceMatrix;
    int** weightMatrix;
    int edgeCounter;
    int vertexCounter;

    QString readListFile(QString filename);//открывает файл что содержит список
    int getMaxVertex(QStringList vertex_pairs);//получает количество вершин
    int** initMatrix(int n);//инициализация нулями матрицы смежности

public:
    Graph();
    ~Graph();

    void ReadMatrix(QString path);

    void getFromListToMatrix(QString filename);


    int getVertexCount();
    int getEdgeCount();
    int getAdjecensyMatrix(int i, int j);

    bool operator ==(Graph to_cmp);
    //vertex deepSearch();
    //vertex wideSearch();
    //Path shortestPath (vertex startPoint, vertex endPoint);
    //опишите прототипы сами

};

#endif
