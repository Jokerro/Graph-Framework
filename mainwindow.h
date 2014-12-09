#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QTextEdit>
#include <QTextLine>
<<<<<<< HEAD
=======
#include <QCheckBox>
>>>>>>> origin/master
#include "graphwidget.h"
#include "httprequest.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0,Graph* gr=0);
    virtual ~MainWindow();
    void setGraphWidget(GraphWidget *widget);
    void openFriend(int id);
    /////
    void setGraph(Graph* t);
    //////


signals:

public slots:

private slots:
    void pressGo();
<<<<<<< HEAD
    void pressPlay();
    void press3d();
=======
    void changePlay();
    void changeAntialiasing();


    void DFS_handler();
    void BFS_handler();
>>>>>>> origin/master

private:
    QTextLine *tlId;
    QTextEdit *teId;
    QPushButton *btnGo;
<<<<<<< HEAD
    QPushButton *btnPlay;
    QPushButton *_3drender;
=======
    QCheckBox *btnPlay;
    QCheckBox *cbAntialiasing;
    QPushButton *btnDFS;
    QPushButton *btnBFS;
>>>>>>> origin/master
    QToolBar *toolBar;
    GraphWidget *graphWidget;
    HttpRequest* req;
    Graph *graph;
<<<<<<< HEAD
=======

>>>>>>> origin/master

};

#endif // MAINWINDOW_H
