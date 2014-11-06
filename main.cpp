#include <QCoreApplication>
#include "saveMatrix.h"



int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   Graph *temp=new Graph();
   temp->ReadMatrix("mat.txt");
   saveMatrix::save("saved.txt", temp);
   delete temp;
   return a.exec();
}
