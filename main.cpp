#include <QCoreApplication>
#include <QApplication>
#include "saveMatrix.h"
#include "mainwindow.h"



int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
//   Graph *temp=new Graph();
//     temp->ReadMatrix("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\mat.txt");
//     saveMatrix::save("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\saved.txt", temp);
//     delete temp;
   QList<vertex*> t1;
   QList< QList<vertex*> > t2;

   t1.push_back(new vertex(1,4,0,0));
   t2.push_back(t1);

   t1.clear();
   t1.push_back(new vertex(0,1,1,1));
   t1.push_back(new vertex(2,2,3,3));
   t1.push_back(new vertex(3,2,5,5));
   t1.push_back(new vertex(4,3,7,7));
   t2.push_back(t1);

   t1.clear();
   t1.push_back(new vertex(1,4,0,0));
   t1.push_back(new vertex(3,2,5,5));
   t1.push_back(new vertex(4,3,7,7));
   t2.push_back(t1);

   t1.clear();
   t1.push_back(new vertex(1,4,0,0));
   t1.push_back(new vertex(4,3,7,7));
   t2.push_back(t1);

   t1.clear();
   t1.push_back(new vertex(1,4,0,0));
   t1.push_back(new vertex(2,2,3,3));
   t1.push_back(new vertex(3,2,5,5));
   t2.push_back(t1);

   Graph g1;
   g1.vertexList=t2;

   g1.DFS(0,2);
   g1.calcPositions();

   Graph *g=new Graph();
   QList<vertex*> f;
   vertex v0(0);
   vertex v1(1);
   vertex v2(2);
   vertex v3(3);
   vertex v4(3);
   vertex v5(3);
   vertex v6(3);
   vertex v7(3);
   vertex v8(3);
   vertex v9(3);
   vertex v10(3);
   vertex v11(3);
   vertex v12(3);
   vertex v13(3);
   vertex v14(3);
   vertex v15(3);
   vertex v16(3);
   vertex v17(3);

   f.append(&v0);
   f.append(&v1);
   f.append(&v2);
   f.append(&v3);
   f.append(&v6);
   f.append(&v7);
   f.append(&v8);
   f.append(&v9);
   f.append(&v13);

   g->vertexList.append(f);
   f.clear();
   f.append(&v1);
   f.append(&v0);
   f.append(&v2);
   f.append(&v3);
   f.append(&v3);
   f.append(&v3);
   f.append(&v3);
   f.append(&v3);
   f.append(&v3);
   f.append(&v3);
   g->vertexList.append(f);
   f.clear();
   f.append(&v2);
   f.append(&v0);
   f.append(&v1);
   f.append(&v3);
   g->vertexList.append(f);
   f.clear();
   f.append(&v3);
   f.append(&v0);
   f.append(&v1);
   f.append(&v2);
   g->vertexList.append(f);
   g->calcPositions();
   f.clear();


     MainWindow w;
     w.setGraph(g);
         w.show();


   return a.exec();
}
