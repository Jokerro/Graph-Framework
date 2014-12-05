#include <QCoreApplication>
#include <QApplication>
#include "saveMatrix.h"
#include "mainwindow.h"
//#include <qt3dversion.h>
//#include "modelview.h"
#include "httprequest.h"
#include <QTime>
#include <QMainWindow>
#include "graphwidget.h"
#include "node.h"


int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

   GraphWidget *widget = new GraphWidget;
   QMainWindow mainWindow;
   mainWindow.setCentralWidget(widget);

   mainWindow.show();
   //Node *node = new Node(widget);
    //widget->scene()->addItem(node);
   Graph *temp=new Graph(widget);

   HttpRequest req;
   QString str="http://api.vk.com/method/friends.get?user_id=13307709";

   req.processRequest(str, temp, 13307709);

    str="http://api.vk.com/method/friends.get?user_id=29121358";
    req.processRequest(str, temp, 29121358);

    str="http://api.vk.com/method/friends.get?user_id=16180281";
    req.processRequest(str, temp, 16180281);

    str="http://api.vk.com/method/friends.get?user_id=27290742";
    req.processRequest(str, temp, 27290742);


   //ModelView go;
   //go.show();

   /*
   Graph *temp=new Graph();
    temp->ReadMatrix("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\mat.txt");
     saveMatrix::save("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\saved.txt", temp);
     delete temp;

*/
   /*QList<int> simple;
   if (a1->BFS(1, 4, &simple)){
       std::cout<<"road"<<std::endl;
       for(int j=0; j<simple.length(); j++){
           std::cout<<simple[j]<<" ";
       }
   }*/
/*
    a1->OpenFileWithGraph("E:\\ProgrammFiles\\Graph-framework\\test.txt");
    for(int j=0; j<a1->getVertexList()[0].length(); j++)
    std::cout<<(a1->getVertexList()[0][j]->GetId())<<" ";
    std::cout<<a1->getVertexList().length();
    a1->calcPositions();
     MainWindow w;
     a.setActiveWindow(&w);
     w.setGraph(a1);
         w.show();

   Graph* test = new Graph();
   MainWindow w;
   a.setActiveWindow(&w);

      void getGraph(Graph* t);
      void showMenu();
      bool BFS_test(Graph* t, QList<int>* list);
      bool DFS_test(Graph* t, QList<int>* list);
      int choice=-1;

      test->OpenFileWithGraph("D:\\Dropbox\\University\\Graph-Framework\\test.txt");

          system("cls");

          showMenu();
          cin>>choice;

          if(choice==1)
          {
              test->OpenFileWithGraph("D:\\Qt\\Tools\\QtCreator\\bin\\Graph_framework\\newGraph.txt");
              choice=2;
          }
          else if(choice==2)
          {
              test->calcPositions();
              w.setGraph(test);
              w.show();


          }
          else if(choice==3)
          {
              QList<int> path;
              if(BFS_test(test,&path)){
                  cout<<"path: "<<endl;
              for(int i=0;i<path.length()-1;i++)
                  cout<<path.at(i)<<"->";
              cout<<path.at(path.length()-1);
          }
              else
                  cout<<"there is no path"<<endl;

      }
          else if(choice==4)
          {
              QList<int> path;
              if(DFS_test(test,&path)){
                  cout<<"path: "<<endl;
              for(int i=0;i<path.length()-1;i++)
                  cout<<path.at(i)<<"->";
              cout<<path.at(path.length()-1);
              }
              else
                  cout<<"there is no path";


          }
*/

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
