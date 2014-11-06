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
public:
    Graph();
    ~Graph();
    void initAdjacensy(int i_VCount); // выделение памяти под матрицу смежности
    void initIncidence(int i_ECount); // выделение памяти под матрицу инцидентности
    void weightMatrixInit(); //выделение памяти под матрицу весов при необходимости
    void initVertexList();   //создание массивa вершин
    void cleanMemory();      //очищение памяти от существующих массивов

    void ReadMatrix(QString path);
    void getFromListToMatrix(QString filename);
    bool compare_graphs(QString path1, QString path2);

    int getVertexCount();
    int getEdgeCount();
    int getAdjecensyMatrixElem(int i, int j);
};

#endif
