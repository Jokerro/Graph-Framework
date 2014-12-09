#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QTextEdit>
#include <QTextLine>
#include <QCheckBox>
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
    void changePlay();
    void changeAntialiasing();


    void DFS_handler();
    void BFS_handler();

private:
    QTextLine *tlId;
    QTextEdit *teId;
    QPushButton *btnGo;
    QCheckBox *btnPlay;
    QCheckBox *cbAntialiasing;
    QPushButton *btnDFS;
    QPushButton *btnBFS;
    QToolBar *toolBar;
    GraphWidget *graphWidget;
    HttpRequest* req;
    Graph *graph;

};

#endif // MAINWINDOW_H
