#ifndef UIMAINWINDOW_H
#define UIMAINWINDOW_H
#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QWidget>

class UImainWindow
{
public:
    UImainWindow();
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUI(QMainWindow *MainWindow);
};

#endif // UIMAINWINDOW_H
