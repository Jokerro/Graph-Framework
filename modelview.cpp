#include "modelview.h"
#include "qglabstractscene.h"
#include "qglabstractmaterial.h"
#include "qglmaterial.h"
#include <QGLTexture2D>
#include <qimage.h>
#include <QColor>
#include <qmath.h>

ModelView::~ModelView()
{
    delete m_scene;
}


void ModelView::initializeGL(QGLPainter *painter)
{
    Q_UNUSED(painter);
    m_scene = QGLAbstractScene::loadScene("E:\\Qt\\Earth.obj");

}

void ModelView::paintGL(QGLPainter *painter)
{

     QGLSceneNode *o = m_scene->mainNode();
     o->draw(painter);

     QVector3D a2(5.749,24.143, 4.01);
     QVector3D a3(7.776, -23.776, 0);
     QVector3D a4(0,0,0);
     drawSphere(painter,a2);
     drawSphere(painter,a3);

     drawArc(25,a3,a2,painter);
}

    QVector3DArray ModelView::CalcArc(int R, int cx, int cy, int cz, QVector3D normal, int segments){
    QVector3DArray vertices;
    float a=normal.x();
    float b=normal.y();
    float c=normal.z();
    float constParam1=sqrt(a*a+c*c);
    float constParam2=sqrt(a*a+b*b+c*c);

    for (int ii = 0; ii < segments; ii++){
            float t = 2.0f * 3.1415926f * float(ii) / float(segments);
            float x=(R/constParam1)*(c*cosf(t)-(a*b*sinf(t))/constParam2);
            float y=(R*constParam1)/constParam2*sinf(t);
            float z=-((R/constParam1)*(a*cosf(t)+(b*c*sinf(t))/constParam2));
            vertices.append(cx+x, cy+y, cz+z);
        }

    return vertices;
}

void ModelView::drawArc(float r, QVector3D startPoint, QVector3D endPoint, QGLPainter *painter){
    QVector3D normal;
    normal=QVector3D::crossProduct(startPoint, endPoint);
    QVector3D sum;
    sum=startPoint+endPoint;
    sum.normalize();
    sum=sum*r;
    drawSphere(painter,sum);
    drawSphere(painter,normal);
    float arcR;
    QVector3D d=startPoint-sum;
    arcR=d.length();
    QVector3DArray vertices=CalcArc(arcR, sum.x(), sum.y(), sum.z(), normal, 64);
    painter->clearAttributes();
    painter->setVertexAttribute(QGL::Position, vertices);
    painter->draw(QGL::LineLoop, 64);
}

void ModelView::drawSphere(QGLPainter *painter, QVector3D position){
    QGLBuilder builder;
    builder << QGL::Faceted;
    builder << QGLSphere();
    QGLMaterial a;
    QColor col(255,255,255,1.0);
  //  QGLTexture2D text;
   // QImage a1("E:\\Qt\\logo.png");
  //  text.setImage(a1);
 //   a.setTexture(&text, a.textureLayerCount());
    a.setAmbientColor(col);
    a.setDiffuseColor(col);
    a.setSpecularColor(col);
    a.setColor(col);
    a.setEmittedLight(col);
    sphere = builder.finalizedSceneNode();
    sphere->setPosition(position);
    sphere->setBackMaterial(&a);
    sphere->setMaterial(&a);
    sphere->draw(painter);
}
