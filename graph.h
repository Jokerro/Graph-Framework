#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include "edge.h"
#include "node.h"
#include "vertex.h"
#include "graphwidget.h"
#include <QString>
#include <iostream>
#include <QFile>
#include <QList>
#include <QTextStream>
#include "VKResponse.h"

using namespace std;

class Graph{

private:

    enum TYPE_VERTEX{WHITE,GRAY,BLACK};
    vector<TYPE_VERTEX> used_topo;
    void dfsTopo(int cur, QList<vertex*>* ans);
    void topoRecur(QList<vertex*>* ans);

    GraphWidget *widget;
    int edgeCounter;
    int vertexCounter;
    QList< QList<vertex*> > vertexList;
    QList<int> used, order;

    QList<int> main_users_indexes;


    void transposedGraphDFS(int v, QList<QList<int> >* transposedGraph, QList<int>* component);
    void strongComponentDFS(int v);
    int getEdgeWeigth(int v, int u);
    void correct(int);
    vertex* checkVertex(int id);

public:
    Graph();
    Graph(GraphWidget *wdg):widget(wdg){    vertexCounter=0;
                                            edgeCounter=0;}
    ~Graph();
    void weightMatrixInit(); //выделение памяти под матрицу весов при необходимости
    void initVertexList();   //создание массивa вершин
    void cleanMemory();      //очищение памяти от существующих массивов

    bool BFS(int startVertex, int finishVertex, QList<int>* visitedVertex);
    void DFS(int vertex1, int vertex2, QList<int>* vertexes);

    void topoSort();

    void minimum_cuts(QList<Node *> *res);

    void getStrongComponents(QList<QList<int> >* components);
    void transposeGraph(QList<QList<int> >* resultGraph);
    void getShortestPath(int vertex1, int vertex2);
    void OpenFileWithGraph(QString filename);
    bool compare_graphs(QString path1, QString path2);
    int getVertexCount();
    int getEdgeCount();
    int getIndex(int id);
    QList < QList<vertex*> > getVertexList(){return vertexList;}
    vertex getVertex(int i, int j){return *vertexList[i][j];}
    bool operator ==(Graph to_compare);

    void setGraphFromVK(QList<VKResponse> friends);
    void addVertexFromVK(VKResponse user);

    void resetGraph();

    bool saveGraph(QString path);

    int ListSize(){return vertexList.size();}

    //выбор вершин для поиска
        static int first_selected;
        static int second_selected;
        static void setChoosed(int v);
};

#endif
