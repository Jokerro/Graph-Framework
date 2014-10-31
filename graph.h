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

    QString readListFile(QString filename);//открывает файл что содержит {1,2},...,{1,m},...,{n,m}
    int getMaxVertex(QStringList vertex_pairs);//режет
    QStringList stringToList(QString temp);
public:
    Graph();
    ~Graph();

    void getFromListToMatrix(QString filename);
    bool compare_graphs(QString path1, QString path2);

    //vertex deepSearch();
    //vertex wideSearch();
    //Path shortestPath (vertex startPoint, vertex endPoint);
    //опишите прототипы сами

};
