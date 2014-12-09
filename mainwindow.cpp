#include "mainwindow.h"
#include <qdebug.h>
#include "graphwidget.h"
#include "modelview.h"
#include "httprequest.h"
#include <QSize>
<<<<<<< HEAD


=======
#include <QMessageBox>
#include <QList>

int Graph::first_selected = 0;
int Graph::second_selected = 0;
>>>>>>> origin/master
MainWindow::MainWindow(QWidget *parent, Graph* gr) :
    QMainWindow(parent)
{
    btnGo = new QPushButton("Go", this);
    connect(btnGo, SIGNAL(released()), this, SLOT(pressGo()));
<<<<<<< HEAD
    btnPlay = new QPushButton("Play/pause", this);
    connect(btnPlay, SIGNAL(released()), this, SLOT(pressPlay()));
    _3drender = new QPushButton("3D", this);
    connect(_3drender, SIGNAL(released()), this, SLOT(press3d()));
    graph=gr;

=======
    btnPlay = new QCheckBox("Physics", this);
    connect(btnPlay, SIGNAL(released()), this, SLOT(changePlay()));
    cbAntialiasing = new QCheckBox();
    connect(cbAntialiasing, SIGNAL(released()),this, SLOT(changeAntialiasing()));

    graph=gr;

    btnDFS = new QPushButton("DFS",this);
    connect(btnDFS, SIGNAL(released()), this, SLOT(DFS_handler()));

    btnBFS = new QPushButton("BFS",this);
    connect(btnBFS, SIGNAL(released()), this, SLOT(BFS_handler()));

>>>>>>> origin/master

    tlId = new QTextLine();
    teId = new QTextEdit();
    QSize teIdSize = teId->document()->size().toSize();
    teIdSize.setWidth(80);
    teIdSize.setHeight(23);
    teId->setMaximumSize(teIdSize);
<<<<<<< HEAD
=======
    cbAntialiasing->setText("Antialiasing");
    cbAntialiasing->setChecked(true);
    btnPlay->setChecked(true);

>>>>>>> origin/master

    toolBar = new QToolBar;
    toolBar->addWidget(teId);
    toolBar->addWidget(btnGo);
<<<<<<< HEAD
    toolBar->addSeparator();
    toolBar->addWidget(btnPlay);
    toolBar->addWidget(_3drender);
=======
    toolBar->addWidget(btnDFS);
    toolBar->addWidget(btnBFS);

    toolBar->addSeparator();
    toolBar->addWidget(btnPlay);
    toolBar->addSeparator();
    toolBar->addWidget(cbAntialiasing);
>>>>>>> origin/master

    this->addToolBar(toolBar);



}

void MainWindow::changeAntialiasing(){

    if(cbAntialiasing->isChecked())
        graphWidget->setAntialiasingEnable(true);
    else
        graphWidget->setAntialiasingEnable(false);
}

void MainWindow::setGraph(Graph* t)
{
    graph=t;
}


void MainWindow::setGraphWidget(GraphWidget *widget){
    graphWidget = widget;

}

<<<<<<< HEAD
=======
void MainWindow::BFS_handler()
{
    if(Graph::first_selected==0||Graph::second_selected==0)
        QMessageBox::information(NULL,"No selected vertexes", "Please, select two vertexes, before pushing this button");
    else
    {
        for(int i=0;i<graph->getVertexList()[graph->getVertexList().size()-1].size();i++){
            this->graph->getVertexList()[graph->getVertexList().size()-1][i]->getNode()->edges()[0]->color=Qt::black;
            this->graph->getVertexList()[graph->getVertexList().size()-1][i]->getNode()->edges()[0]->update();
        }

        QList<int> *vertexes = new QList<int>;
        this->graph->BFS(Graph::first_selected,Graph::second_selected,vertexes);

        for(int i=0;i<vertexes->size();i++)
        {
            for(int j=0;j<graph->getVertexList().size();j++)
            {
                if(graph->getVertexList()[j][0]->GetUserId()==vertexes->at(i))
                {
                    for(int k=0;k<this->graph->getVertexList()[j][0]->getNode()->edges().size();k++)
                    {
                       if(this->graph->getVertexList()[j][0]->getNode()->edges()[k][0].dest->getTrueId()==vertexes->at(i))
                        {this->graph->getVertexList()[j][0]->getNode()->edges()[k]->color=Qt::red;}
                    }
                }
            }
        }


        for(int i=0;i<graph->getVertexList()[graph->getVertexList().size()-1].size();i++)
            this->graph->getVertexList()[graph->getVertexList().size()-1][i]->getNode()->edges()[0]->update();
        //QMessageBox::information(NULL,"Успех","Длина пути = "+QString::number(vertexes->size()));

        Graph::second_selected=0;
        Graph::first_selected =0;
    }
}

void MainWindow::DFS_handler()
{
    //qDebug()<<this->graph->test();
    if(Graph::first_selected==0||Graph::second_selected==0)
        QMessageBox::information(NULL,"No selected vertexes", "Please, select two vertexes, before pushing this button");
    else
    {
        for(int i=0;i<graph->getVertexList()[graph->getVertexList().size()-1].size();i++){
            this->graph->getVertexList()[graph->getVertexList().size()-1][i]->getNode()->get_edges()[0]->color=Qt::black;
            this->graph->getVertexList()[graph->getVertexList().size()-1][i]->getNode()->get_edges()[0]->update();
        }

        QList<int> *vertexes = new QList<int>;
        this->graph->DFS(Graph::first_selected,Graph::second_selected,vertexes);

        qDebug()<<"s1";

        for(int i=0;i<vertexes->size();i++)
        {
            for(int j=0;j<graph->getVertexList().size();j++)
            {
                if(graph->getVertexList()[j][0]->GetUserId()==vertexes->at(i))
                {
                    for(int k=0;k<this->graph->getVertexList()[j][0]->getNode()->get_edges().size();k++)
                    {
                       if(this->graph->getVertexList()[j][0]->getNode()->get_edges()[k][0].dest->getTrueId()==vertexes->at(i))
                        {qDebug()<<this->graph->getVertexList()[j][0]->getNode()->get_edges()[k]->color;
                           this->graph->getVertexList()[j][0]->getNode()->get_edges()[k]->color=Qt::red;
                           this->graph->getVertexList()[j][0]->getNode()->get_edges()[k]->update();
                           this->graph->getVertexList()[j][0]->getNode()->el->at(k)->update();
                           qDebug()<<this->graph->getVertexList()[j][0]->getNode()->get_edges()[k]->color;}
                    }
                }
            }
        }

        this->graphWidget->upd();
        for(int i=0;i<graph->getVertexList()[graph->getVertexList().size()-1].size();i++)
            this->graph->getVertexList()[graph->getVertexList().size()-1][i]->getNode()->get_edges()[0]->update();
        //QMessageBox::information(NULL,"Успех","Длина пути = "+QString::number(vertexes->size()));

        Graph::second_selected=0;
        Graph::first_selected =0;
    }
}


>>>>>>> origin/master
void MainWindow::pressGo(){
    QString str="http://api.vk.com/method/users.get?user_ids="+teId->toPlainText()+"&fields=photo_100,country,city&v=5.27";
    qDebug()<<str;
    req = new HttpRequest();
    req->processRequest(str, graph, teId->toPlainText().toInt(), req);
}

<<<<<<< HEAD
void MainWindow::pressPlay(){
=======
void MainWindow::openFriend(int id){
    QString str="http://api.vk.com/method/users.get?user_ids="+QString::number(id)+"&fields=photo_100,country,city&v=5.27";
    qDebug()<<str;
    req = new HttpRequest();
    req->processRequest(str, graph, id, req);
}

void MainWindow::changePlay(){
>>>>>>> origin/master
    //action here
    if(graphWidget->isPhysicsDisabled())
        graphWidget->setPhysicsEnable(false);
    else
        graphWidget->setPhysicsEnable(true);

<<<<<<< HEAD
}
void MainWindow::press3d(){
    int iLen=graph->getVertexList().length();
    for(int i=0; i<iLen; i++)
        for(int j=0; j<graph->getVertexList()[i].length(); j++)
            graph->getVertexList()[i][j]->calcCoords();

    ModelView *w1 = new ModelView();
    w1->setGraph(graph);
    w1->showMaximized();
=======
>>>>>>> origin/master
}

MainWindow::~MainWindow()
{

}
