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


    Graph* a1= new Graph();
    a1->OpenFileWithGraph("C:\\Users\\Ruslan\\Documents\\GitHub\\Graph-Framework\\email-Enron.txt");
    for(int j=0; j<a1->getVertexList()[0].length(); j++)
    std::cout<<(a1->getVertexList()[0][j]->GetId())<<" ";
    std::cout<<a1->getVertexList().length();
    a1->calcPositions();

     MainWindow w;
     w.setGraph(a1);
         w.show();


   return a.exec();
}
