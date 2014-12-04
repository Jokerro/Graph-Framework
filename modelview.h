#ifndef MODELVIEW_H
#define MODELVIEW_H
#define ARC_SEGMENTS_COUNT 64
#include "qglview.h"
#include <QGLTexture2D>
#include <qglbuilder.h>
#include <QGLCube>
#include <QGLSphere>
#include <QGLCylinder>

class QGLAbstractScene;
class QGLSceneNode;

class ModelView : public QGLView
{
    Q_OBJECT
public:
    ModelView(QWindow *parent = 0) : QGLView(parent){};
    ~ModelView();
    QVector3DArray CalcArc(int R, int cx, int cy, int cz, QVector3D normal, int segments);
    void drawArc(float r, QVector3D startPoint, QVector3D endPoint, QGLPainter *painter);
    void drawSphere(QGLPainter *painter, QVector3D position);
protected:
    void initializeGL(QGLPainter *painter);
    void paintGL(QGLPainter *painter);

private:
    QGLAbstractScene *m_scene;
    QGLTexture2D text;
    QGLSceneNode *cube;
    QGLSceneNode *sphere;
    QGLSceneNode *cylinder;
};

#endif
