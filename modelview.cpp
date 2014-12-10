#include "modelview.h"
#include "qglabstractscene.h"
#include "qglabstractmaterial.h"
#include <QGLMaterial>
#include <QGLTexture2D>
#include <QQuickQGraphicsTransform3D>
#include <QGeometryData>
#include <qimage.h>
#include <QColor>
#include <QGraphicsRotation3D>
#include <qmath.h>

#define PI 3.1415

 ModelView::ModelView(QWindow *parent) : QGLView(parent){
     startPoint.setX(25);
     startPoint.setY(0);
     startPoint.setZ(0);
     QGLBuilder builder;
     builder << QGL::Faceted;
     builder << QGLSphere(0.1);
     sphere = builder.finalizedSceneNode();
     sphereMaterial=new QGLMaterial;
 }

ModelView::~ModelView()
{
    delete m_scene;
    delete sphereTexture;
    delete sphereMaterial;
    delete textureImage;
}


void ModelView::initializeGL(QGLPainter *painter)
{
    Q_UNUSED(painter);
    m_scene = QGLAbstractScene::loadScene("res/Earth.obj");
    //sphereTexture=new QGLTexture2D();
    QColor red(255,0,0,1);
    //textureImage=new QImage("res/logo.png");
    //sphereTexture->setImage(*textureImage);
    //sphereMaterial->setTexture(sphereTexture);
    sphereMaterial->setShininess(128);
    sphereMaterial->setSpecularColor(red);
    sphereMaterial->setEmittedLight(red);
    sphere->setMaterial(sphereMaterial);
    int len=workGraph->getVertexList().length();
    for(int i=0; i<len; i++)
    {
        QVector3D temp=CalcCoordinate(workGraph->getVertexList()[i][0]->getLon(), workGraph->getVertexList()[i][0]->getLat());
        int jLen=workGraph->getVertexList()[i].length();
        for(int j=1; j<jLen; j++)
        {
            coordinats.append(temp);
            coordinats.append(CalcCoordinate(workGraph->getVertexList()[i][j]->getLon(), workGraph->getVertexList()[i][j]->getLat()));
        }
    }
}

void ModelView::paintGL(QGLPainter *painter)
{
     QGLSceneNode *o = m_scene->mainNode();
     o->draw(painter);
     drawGraph(painter);
}

QVector3DArray ModelView::CalcArc(float R, float cx, float cy, float cz, QVector3D normal, int segments){
    QVector3DArray vertices;
    float a=normal.x();
    float b=normal.y();
    float c=normal.z();
    float constParam1=sqrtf(a*a+c*c);
    float constParam2=sqrtf(a*a+b*b+c*c);
    for (int ii = 0; ii < segments; ii++){
            float t = 2.0f * 3.1415926f * float(ii) / float(segments);
            float x=(R/constParam1)*(c*cosf(t)-(a*b*sinf(t))/constParam2);
            float y=(R*constParam1)/constParam2*sinf(t);
            float z=-((R/constParam1)*(a*cosf(t)+(b*c*sinf(t))/constParam2));
            vertices.append(cx+x, cy+y, cz+z);
        }

    return vertices;
}

QVector3D ModelView::CalcCoordinate(float lat, float lon){
    float radlat = lat*PI/180.0;
    float radlon = lon*PI/180.0;
    QVector3D coords;

    rotateY(0,0)=(cosf(-radlon));
    rotateY(0,1)=(0);
    rotateY(0,2)=(sinf(-radlon));
    rotateY(1,0)=(0);
    rotateY(1,1)=(1);
    rotateY(1,2)=(0);
    rotateY(2,0)=(-sinf(-radlon));
    rotateY(2,1)=(0);

    rotateZ(0,0)=(cosf(-radlat));
    rotateZ(0,1)=(-sinf(-radlat));
    rotateZ(0,2)=(0);
    rotateZ(1,0)=(sinf(-radlat));
    rotateZ(1,1)=(cosf(-radlat));
    rotateZ(1,2)=(0);
    rotateZ(2,0)=(0);
    rotateZ(2,1)=(0);
    rotateZ(2,2)=(1);

    coords=startPoint*rotateZ;
    coords=coords*rotateY;
    return coords;
}

void ModelView::drawArc(QVector3D startPoint, QVector3D endPoint, QGLPainter *painter){
    QVector3D normal;
    normal=QVector3D::crossProduct(startPoint, endPoint);
    QVector3D sum;
    sum.setX((endPoint.x()+startPoint.x())/2.0);
    sum.setY((endPoint.y()+startPoint.y())/2.0);
    sum.setZ((endPoint.z()+startPoint.z())/2.0);
    float arcR;
    QVector3D radius=startPoint-sum;
    arcR=radius.length();
    QVector3DArray vertices=CalcArc(arcR, sum.x(), sum.y(), sum.z(), normal, ARC_SEGMENTS_COUNT);
    painter->clearAttributes();
    painter->setVertexAttribute(QGL::Position, vertices);
    painter->setStandardEffect(QGL::LitMaterial);
    painter->draw(QGL::LineLoop, ARC_SEGMENTS_COUNT);
    painter->clearAttributes();
}

void ModelView::drawGraph(QGLPainter *painter){
   QVector3D start;
   QVector3D end;
   int i=1;
   foreach(QVector3D a, coordinats){
        drawSphere(painter, a);
       switch(i%2)
       {
            case 1: start=a; break;
            case 0: end=a;  drawArc(start, end, painter); break;
       }
       i++;
   }
}

void ModelView::drawSphere(QGLPainter *painter, QVector3D position){
    painter->clearAttributes();
    sphere->setPosition(position);
    sphere->draw(painter);
}

void ModelView::setGraph(Graph *a){
    workGraph=a;
}
