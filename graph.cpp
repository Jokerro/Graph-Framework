#include "graph.h"
#include <iostream>
#include <QFile>

Graph::Graph()
{
    vertexCounter=0;
    edgeCounter=0;
    weightMatrix = NULL;
    incidenceMatrix = NULL;
    adjacensyMatrix = NULL;

}

Graph::~Graph() {}

bool Graph::compare_graphs(QString path1, QString path2)
{
   QFile graph1(path1);
   QFile graph2(path2);


}
