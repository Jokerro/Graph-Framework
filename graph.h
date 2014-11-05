#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include "edge.h"
#include "vertex.h"
#include <QString>
#include <iostream>
#include <QFile>
#include <QVector>

using namespace std;

class Graph{

private:
    QVector <vertex> Vertexes;
    QVector <edge> Edges;
    int** adjacensyMatrix;
    int** incidenceMatrix;
    int** weightMatrix;
    int edgeCounter;
    int vertexCounter;

    QString readListFile(QString filename);//открывает файл что содержит список
    int getMaxVertex(QStringList vertex_pairs);//получает количество вершин
    int** initMatrix(int n);//инициализация нулями матрицы смежности (УДАЛИТЬ)

public:
    Graph();
     ~Graph();
    void init(int i_ECount, int i_VCount); // фактический конструктор, создает и инициализурет объект графа
    void weightMatrixInit(); //инициализирует матрицу весов при необходимости
    void ReadMatrix(QString path);

    void getFromListToMatrix(QString filename);
    bool compare_graphs(QString path1, QString path2);

    int getVertexCount();//get-ер количества вершин
    int getEdgeCount();//get-ер количества ребер
    int getAdjecensyMatrix(int i, int j);//get-ер элемента матрицы смежности
    //vertex deepSearch();
    //vertex wideSearch();
    //Path shortestPath (vertex startPoint, vertex endPoint);
    //опишите прототипы сами

};

#endif
