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

     Graph a1[100];
     for(int i=0; i<100; i++)
     {
         QList <int> b;
         b.append(4);
         a1[i].vertexList.append(b);
     }
     for(int i=0; i<100; i++)
         a1[i].cleanMemory();
     MainWindow w;
         w.show();

   return a.exec();
}
