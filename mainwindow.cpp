#include "mainwindow.h"
#include <qdebug.h>
#include "graphwidget.h"
#include "httprequest.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    btnGo = new QPushButton("Gooo!", this);
    connect(btnGo, SIGNAL(released()), this, SLOT(handleButton()));

    toolBar = new QToolBar;
    toolBar->addWidget(btnGo);
    this->addToolBar(toolBar);



}

void MainWindow::setGraphWidget(GraphWidget *widget){
    graphWidget = widget;
}

void MainWindow::handleButton(){
    //action here
    qDebug()<<"GO is pressed";
    if(graphWidget->isPhysicsDisabled())
        graphWidget->setPhysicsEnable(false);
    else
        graphWidget->setPhysicsEnable(true);




}

MainWindow::~MainWindow()
{

}
