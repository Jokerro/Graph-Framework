#include <QCoreApplication>
#include <QApplication>
#include "saveMatrix.h"
#include <qt3dversion.h>
#include "modelview.h"
#include <QTime>
#include <QMainWindow>
#include <QToolBar>
#include <QPushButton>
#include "graphwidget.h"
#include "mainwindow.h"
#include "node.h"
#include <qdebug.h>


int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

   GraphWidget *graphWidget = new GraphWidget;
   Graph* graph = new Graph(graphWidget);

   MainWindow mainWindow(NULL,graph);

   mainWindow.setGraphWidget(graphWidget);
   mainWindow.setCentralWidget(graphWidget);
   mainWindow.showMaximized();


   return a.exec();


}

void showMenu()
{
    system("cls");

    cout<<"\t\t\tSprint 2 Demo"<<endl<<
        //  "1 - Load graph from .txt file"<<endl<<
          "2 - Visualise"<<endl<<
          "3 - BFS"<<endl<<
          "4 - DFS"<<endl;
}

bool BFS_test(Graph* t, QList<int>* list)
{
    system("cls");

    cout<<"Type first vertex:"<<endl;
    int v1,v2;
    cin>>v1;
    cout<<"Type second vertex:"<<endl;
    cin>>v2;

    return t->BFS(v1,v2,list);
}

bool DFS_test(Graph* t, QList<int>* list)
{
    system("cls");


    cout<<"Type first vertex:"<<endl;
    int v1,v2;
    cin>>v1;
    cout<<"Type second vertex:"<<endl;
    cin>>v2;

    t->DFS(v1,v2,list);

    if(list->length()==0)
        return false;
    else return true;
}

void getGraph(Graph* t)
{
    system("cls");

    cout<<"Type full file path:"<<endl;

    string path;

    cin>>path;

    t->OpenFileWithGraph(path.c_str());
    system("cls");

}
