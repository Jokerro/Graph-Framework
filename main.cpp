#include <QCoreApplication>
#include <QApplication>
#include "saveMatrix.h"
#include "mainwindow.h"



int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   Graph *temp=new Graph();
     temp->ReadMatrix("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\mat.txt");
     saveMatrix::save("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\saved.txt", temp);
     delete temp;

     MainWindow w;
         w.show();

   return a.exec();
}
