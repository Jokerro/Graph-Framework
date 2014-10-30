#include <stdlib.h>
#include <vector>
#include "edge.h"
#include "vertex.h"
#include "qstring.h"
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
    //vertex deepSearch();
    //vertex wideSearch();
    //Path shortestPath (vertex startPoint, vertex endPoint);
    //опишите прототипы сами

};
