#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QTextEdit>
#include <QTextLine>
#include "graphwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    void setGraphWidget(GraphWidget *widget);


signals:

public slots:

private slots:
    void pressGo();
    void pressPlay();

private:
    QTextLine *tlId;
    QTextEdit *teId;
    QPushButton *btnGo;
    QPushButton *btnPlay;
    QToolBar *toolBar;
    GraphWidget *graphWidget;

};

#endif // MAINWINDOW_H
