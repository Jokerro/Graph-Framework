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
}

void MainWindow::pressGo(){
    //do something
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
