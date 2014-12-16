#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QTextEdit>
#include <QTextLine>
#include <QLabel>
#include <QCheckBox>
#include "graphwidget.h"
#include "httprequest.h"
#include "modelview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0,Graph* gr=0);
    virtual ~MainWindow();
    void setGraphWidget(GraphWidget *widget);
    void setGraph(Graph* t);

    static void updateLabels(int vert, int ed);
    static void createLabels();

    //////


signals:

public slots:

private slots:
    void pressGo();
    void press3d();
    void pressStrong();
    void pressDFS();
    void pressBFS();
    void selectPlay();
    void selectAntialiasing();
    void selectShowHideWeight();
    void Cuts_handler();
private:
    ModelView *viewport;
    QTextLine *tlId;
    QTextEdit *teId;
    QPushButton *btnGo;
    QPushButton *btn3Drender;
    QPushButton *btnDFS;
    QPushButton *btnBFS;
    QPushButton *btnStong;    
    QPushButton *btnCuts;

    static QLabel *vertexInfo;
    static QLabel *edgeInfo;

    QCheckBox *cbWeight;
    QCheckBox *cbPlay;
    QCheckBox *cbAntialiasing;
    QToolBar *toolBar;

    GraphWidget *graphWidget;
    HttpRequest* req;
    Graph *graph;
    void paintComponent(QList<int> component, int color );
};

#endif // MAINWINDOW_H
