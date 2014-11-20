#include "mainwindow.h"
#include <qmath.h>

MainWindow::MainWindow(QWidget *parent)
    : QGLWidget(parent)
{
    mVertexSize = 10;
    xTra = 0.0f;
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
        paintGraph();

        qglColor(Qt::white);
}

void MainWindow::drawEdge(int x1, int y1, int x2, int y2, color c){
    glBegin(GL_LINE_STRIP);
        switch(c){
            case BLACK: glColor3f(COLOR_BLACK); break;
            case WHITE: glColor3f(COLOR_WHITE); break;
            case BLUE: glColor3f(COLOR_BLUE); break;
            case RED: glColor3f(COLOR_RED); break;
            case MAGENTA: glColor3f(COLOR_MAGENTA); break;
            case CYAN: glColor3f(COLOR_CYAN); break;

        default: glColor3f(0.0,0.0,0.0);
        }
            glVertex2f(x1+0.5*mVertexSize, y1+0.5*mVertexSize);
            glVertex2f(x2+0.5*mVertexSize, y2+0.5*mVertexSize);
        glEnd();

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


void MainWindow::paintGraph()
{
    int tempX, tempX1;
    int tempY, tempY1;
  /*  for(int i=0; i<toPaint->getVertexList().length(); i++)
        for(int j=1; j<toPaint->getVertexList()[i].length(); j++)
        {
            tempX=0;
            tempX1=0;
            tempY=0;
            tempY1=0;
            tempX=toPaint->getVertexList()[i][0]->getX();
            tempX1=toPaint->getVertexList()[i][j]->getX();
            tempY=toPaint->getVertexList()[i][0]->getY();
            tempY1=toPaint->getVertexList()[i][j]->getY();
            if((tempX < mWindowWidth-xTra && tempY < mWindowHeight-zTra)// &&
                //    tempX > xTra-mWindowWidth && tempY > zTra-mWindowHeight)//||
              // (tempX1 < mWindowWidth-xTra && tempY1 < mWindowHeight-zTra &&
              //      tempX1 > xTra-mWindowWidth && tempY1 > zTra-mWindowHeight)
                    )
           {
           drawEdge(toPaint->getVertexList()[i][0]->getX(), toPaint->getVertexList()[i][0]->getY(),
                    toPaint->getVertexList()[i][j]->getX(), toPaint->getVertexList()[i][j]->getY(), RED);
            }
            }*/
    for(int i=0; i<toPaint->getVertexList().length(); i++)
    {
        tempX = 0;
        tempY = 0;

        tempX = toPaint->getVertex(i,0).getX();
        tempY = toPaint->getVertex(i,0).getY();
        if(tempX < mWindowWidth-xTra && tempY < mWindowHeight-zTra &&
               - tempX > xTra-mWindowWidth && -tempY > zTra-mWindowHeight
                ){
            drawVertex(tempX, tempY);
            toPaint->getVertexList()[i][0]->markAsPainted();
        }

    }
}

void MainWindow::mousePressEvent(QMouseEvent *pe){
    ptrMousePosition = pe->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *pe){
    xTra -= ptrMousePosition.x() - pe->x();
    zTra -= ptrMousePosition.y() - pe->y();

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
