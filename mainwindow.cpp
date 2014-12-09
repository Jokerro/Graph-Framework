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
    btnPlay = new QCheckBox("Physics", this);
    connect(btnPlay, SIGNAL(released()), this, SLOT(changePlay()));
    cbAntialiasing = new QCheckBox();
    connect(cbAntialiasing, SIGNAL(released()),this, SLOT(changeAntialiasing()));


    tlId = new QTextLine();
    teId = new QTextEdit();
    QSize teIdSize = teId->document()->size().toSize();
    teIdSize.setWidth(80);
    teIdSize.setHeight(23);
    teId->setMaximumSize(teIdSize);
    cbAntialiasing->setText("Antialiasing");
    cbAntialiasing->setChecked(true);
    btnPlay->setChecked(true);


    toolBar = new QToolBar;
    toolBar->addWidget(teId);
    toolBar->addWidget(btnGo);
    toolBar->addSeparator();
    toolBar->addWidget(btnPlay);
    toolBar->addSeparator();
    toolBar->addWidget(cbAntialiasing);

    this->addToolBar(toolBar);



}

void MainWindow::changeAntialiasing(){

    if(cbAntialiasing->isChecked())
        graphWidget->setAntialiasingEnable(true);
    else
        graphWidget->setAntialiasingEnable(false);
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

void MainWindow::openFriend(int id){
    QString str="http://api.vk.com/method/users.get?user_ids="+QString::number(id)+"&fields=photo_100,country,city&v=5.27";
    qDebug()<<str;
    req = new HttpRequest();
    req->processRequest(str, graph, id, req);
}

void MainWindow::changePlay(){
    //action here
    if(graphWidget->isPhysicsDisabled())
        graphWidget->setPhysicsEnable(false);
    else
        graphWidget->setPhysicsEnable(true);

}

MainWindow::~MainWindow()
{

}
