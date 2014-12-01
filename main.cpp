#include <QCoreApplication>
#include <QApplication>
#include "saveMatrix.h"
#include "mainwindow.h"
#include <Qt3D>
#include "modelview.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Graph* test = new Graph();

    ModelView m;
    m.show();
return a.exec();
}
