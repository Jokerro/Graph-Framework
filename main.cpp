#include <QCoreApplication>
#include "saveMatrix.h"



int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);

   Graph *temp=new Graph();
     temp->ReadMatrix("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\mat.txt");
     saveMatrix::save("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\saved.txt", temp);
     delete temp;

   return a.exec();
}
