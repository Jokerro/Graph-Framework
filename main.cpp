#include <QCoreApplication>
#include <QApplication>
#include "saveMatrix.h"
#include "mainwindow.h"



int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
<<<<<<< HEAD
//   Graph *temp=new Graph();
//     temp->ReadMatrix("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\mat.txt");
//     saveMatrix::save("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\saved.txt", temp);
//     delete temp;
   Graph *g=new Graph();
   QList<vertex*> f;
   vertex v0(0);
   vertex v1(1);
   vertex v2(2);
   vertex v3(3);
   f.append(&v0);
   f.append(&v1);
   f.append(&v2);
   f.append(&v3);
   g->vertexList.append(f);
   f.clear();
   f.append(&v1);
   f.append(&v0);
   f.append(&v2);
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
=======
   Graph *temp=new Graph();
  // temp->ReadMatrix("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\mat.txt");
   //saveMatrix::save("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\saved.txt", temp);
   // temp->OpenFileWithGraph("D:\\CA-HepTh.txt");

    delete temp;
    MainWindow w;
    w.show();

   return 0;
>>>>>>> origin/master
}
