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

public:
    Graph();
    ~Graph();
    bool compare_graphs(QString path1, QString path2);
    int getVertexCount();
    int getEdgeCount();
    int getAdjecensyMatrix(int i, int j);
    //vertex deepSearch();
    //vertex wideSearch();
    //Path shortestPath (vertex startPoint, vertex endPoint);
    //опишите прототипы сами

};

#endif
