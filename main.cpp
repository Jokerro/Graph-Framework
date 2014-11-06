#include <QCoreApplication>
#include "saveMatrix.h"



int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   Graph *temp=new Graph();
   temp->ReadMatrix("E:\\ProgrammFiles\\Graph-Framework\\mat.txt");
   saveMatrix::save("E:\\ProgrammFiles\\Graph-Framework\\saved.txt", temp);
   delete temp;
   return a.exec();
}
