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

<<<<<<< HEAD
=======
    QString readListFile(QString filename);//открывает файл что содержит {1,2},...,{1,m},...,{n,m}
    int getMaxVertex(QStringList vertex_pairs);//режет
    QStringList stringToList(QString temp);
>>>>>>> 0a90d2fee698eb6bb1c3e592f24a6e1a94331966
public:
    Graph();
    ~Graph();

    void getFromListToMatrix(QString filename);
    bool compare_graphs(QString path1, QString path2);
<<<<<<< HEAD
    int getVertexCount();
    int getEdgeCount();
    int getAdjecensyMatrix(int i, int j);
=======

>>>>>>> 0a90d2fee698eb6bb1c3e592f24a6e1a94331966
    //vertex deepSearch();
    //vertex wideSearch();
    //Path shortestPath (vertex startPoint, vertex endPoint);
    //опишите прототипы сами

};

#endif
