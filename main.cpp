#include <QCoreApplication>
#include <QApplication>
//#include <qt3dversion.h>
//#include "modelview.h"

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

   graphWidget->setGraph(graph);
   MainWindow::createLabels();
   MainWindow mainWindow(NULL,graph);
   mainWindow.setGraphWidget(graphWidget);
   mainWindow.setCentralWidget(graphWidget);
   mainWindow.showMaximized();

   return a.exec();

}
