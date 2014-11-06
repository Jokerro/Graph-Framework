#include <QCoreApplication>
#include "saveMatrix.h"



int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   Graph *temp=new Graph();
   temp->ReadMatrix("mat.txt");
   saveMatrix::save("saved.txt", temp);

   Graph* t1 = new Graph();
   t1->ReadMatrix("D:\\Qt\\Tools\\QtCreator\\path2.txt");
   saveMatrix::save("D:\\Qt\\Tools\\QtCreator\\path2_saved.txt",t1);
   /*Graph t2;
   t2.ReadMatrix("D:\\Qt\\Tools\\QtCreator\\path2.txt");
   bool tr;
   //tr=(t1==t2);*/
   delete t1;
   delete temp;
   return a.exec();
}
