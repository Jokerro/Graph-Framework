#include "mainwindow.h"
#include <qdebug.h>
#include "graphwidget.h"
#include "modelview.h"
#include "httprequest.h"
#include <QSize>


MainWindow::MainWindow(QWidget *parent, Graph* gr) :
    QMainWindow(parent)
{
    btnGo = new QPushButton("Go", this);
    connect(btnGo, SIGNAL(released()), this, SLOT(pressGo()));
    btnPlay = new QPushButton("Play/pause", this);
    connect(btnPlay, SIGNAL(released()), this, SLOT(pressPlay()));
    _3drender = new QPushButton("3D", this);
    connect(_3drender, SIGNAL(released()), this, SLOT(press3d()));
    graph=gr;


    tlId = new QTextLine();
    teId = new QTextEdit();
    QSize teIdSize = teId->document()->size().toSize();
    teIdSize.setWidth(80);
    teIdSize.setHeight(23);
    teId->setMaximumSize(teIdSize);

    toolBar = new QToolBar;
    toolBar->addWidget(teId);
    toolBar->addWidget(btnGo);
    toolBar->addSeparator();
    toolBar->addWidget(btnPlay);
    toolBar->addWidget(_3drender);

    this->addToolBar(toolBar);



}

void MainWindow::setGraphWidget(GraphWidget *widget){
    graphWidget = widget;

}

void MainWindow::pressGo(){
    QString str="http://api.vk.com/method/users.get?user_ids="+teId->toPlainText()+"&fields=photo_100,country,city&v=5.27";
    qDebug()<<str;
    req = new HttpRequest();
    req->processRequest(str, graph, teId->toPlainText().toInt(), req);
}

void MainWindow::pressPlay(){
    //action here
    if(graphWidget->isPhysicsDisabled())
        graphWidget->setPhysicsEnable(false);
    else
        graphWidget->setPhysicsEnable(true);

}
void MainWindow::press3d(){
    int iLen=graph->getVertexList().length();
    for(int i=0; i<iLen; i++)
        for(int j=0; j<graph->getVertexList()[i].length(); j++)
            graph->getVertexList()[i][j]->calcCoords();

    ModelView *w1 = new ModelView();
    w1->setGraph(graph);
    w1->showMaximized();
}

MainWindow::~MainWindow()
{

}
