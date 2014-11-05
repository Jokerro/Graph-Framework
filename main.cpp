#include <QCoreApplication>
#include "saveMatrix.h"



int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   Graph temp,temp1;
   //temp.getFromListToMatrix("D:\\Qt\\Tools\\QtCreator\\path1.txt");
   // temp.ReadMatrix("C:\\Users\\mrev1l\\Downloads\\newFile.txt");
   //temp.compare_graphs("D:\\Qt\\Tools\\QtCreator\\path1.txt","D:\\Qt\\Tools\\QtCreator\\path2.txt");
   //temp.getFromListToMatrix("D:\\Qt\\Tools\\QtCreator\\path1.txt");
   temp1.ReadMatrix("D:\\mat.txt");
   //bool aa=(temp==temp);
   return a.exec();
}
