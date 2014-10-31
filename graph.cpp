#include "graph.h"

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

int Graph::getVertexCount(){
    return vertexCounter;
}

int Graph::getEdgeCount(){
    return edgeCounter;
}

int Graph::getAdjecensyMatrix(int i, int j){
    return adjacensyMatrix[i][j];
}

