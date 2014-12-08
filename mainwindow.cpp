#include "mainwindow.h"
#include <qdebug.h>
#include "graphwidget.h"
#include "httprequest.h"
#include <QSize>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    btnGo = new QPushButton("Go", this);
    connect(btnGo, SIGNAL(released()), this, SLOT(pressGo()));
    btnPlay = new QPushButton("Play/pause", this);
    connect(btnPlay, SIGNAL(released()), this, SLOT(pressPlay()));



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

    this->addToolBar(toolBar);



}

void MainWindow::setGraphWidget(GraphWidget *widget){
    graphWidget = widget;
    graph = new Graph(graphWidget);
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

MainWindow::~MainWindow()
{

}
