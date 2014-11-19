#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGLWidget>
#include <QtOpenGL>
#include <QTimer>
#include <graph.h>
#include <qmath.h>


class MainWindow : public QGLWidget
{
    Q_OBJECT

private:
    int mVertexSize;
    int mWindowWidth;
    int mWindowHeight;

    Graph* toPaint;

    GLfloat zTra; // z текущая координата перемещения сцены
    GLfloat xTra; // x текущая координата перемещения сцены
    GLfloat nSca; // коэф масштабирования

    QPoint ptrMousePosition; // координата указателя мыши


protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void mouseMoveEvent(QMouseEvent* pe);
    void mousePressEvent(QMouseEvent* pe);
    void wheelEvent(QWheelEvent* pe);

public:

    void setGraph(Graph *a){toPaint=a;}
    void drawVertex(int x, int y);
    void drawEdge(int x1, int y1, int x2, int y2);
    void paintGraph();
    // Скалирование сцены
    void scale_plus();
    void scale_minus();

    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
