#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QGLWidget(parent)
{
    mVertexSize = 10;
    zTra = 0.0f;
    nSca = 1;

}

void MainWindow::initializeGL(){
    qglClearColor(Qt::white);
}

void MainWindow::resizeGL(int w, int h){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)w, (GLint)h);
    mWindowHeight = h;
    mWindowWidth = w;
}

void MainWindow::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // чистим буфер изображения и буфер глубины
        glMatrixMode(GL_PROJECTION); // устанавливаем матрицу
        glLoadIdentity(); // загружаем матрицу
        glOrtho(0,mWindowWidth,mWindowHeight,0,1,0); // подготавливаем плоскости для матрицы
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glTranslatef(xTra, zTra, 0.0f);
        glScalef(nSca, nSca, nSca);

        for(int j=0; j<10000; j+=20)
        for(int i=0; i<10000; i+=20){
            drawVertex(i,j);
//            drawEdge(i,j,i+i,j+j);
        }


        qglColor(Qt::white);
}


void MainWindow::drawVertex(int x, int y){
    glBegin(GL_POLYGON);
            glColor3f(1.0,0.0,1.0);// Цвет выделенной области
            // Координаты выделенной области
            glVertex2f(x, y);
            glVertex2f(x+mVertexSize, y);
            glVertex2f(x+mVertexSize, y+mVertexSize);
            glVertex2f(x, y+mVertexSize);
        glEnd();

    // Форма вершины - окружность
   /*
    int r = 5;
    int num_segments = 16;
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,0.0,1.0);//
        for (int ii = 0; ii < num_segments; ii++)   {
            float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
            float x = r * cosf(theta);//calculate the x component
            float y = r * sinf(theta);//calculate the y component
            glVertex2f(x + cx, y + cy);//output vertex
        }
        glEnd();
   */
}


void MainWindow::mousePressEvent(QMouseEvent *pe){
    ptrMousePosition = pe->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *pe){
    xTra += ptrMousePosition.x() - pe->x();
    zTra += ptrMousePosition.y() - pe->y();

    ptrMousePosition = pe->pos();
    updateGL();
}

void MainWindow::wheelEvent(QWheelEvent* pe){
    if ((pe->delta())>0) scale_plus(); else if ((pe->delta())<0) scale_minus();
       updateGL();
}

void MainWindow::scale_minus(){
    nSca = nSca / 1.1;
}

void MainWindow::scale_plus(){
    nSca = nSca * 1.1;
}

MainWindow::~MainWindow()
{

}
