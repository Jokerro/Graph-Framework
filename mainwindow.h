#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
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
    void handleButton();

private:
    QPushButton *btnGo;
    QToolBar *toolBar;
    GraphWidget *graphWidget;

};

#endif // MAINWINDOW_H
