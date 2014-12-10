#ifndef MODELVIEW_H
#define MODELVIEW_H
#define ARC_SEGMENTS_COUNT 64
#include "graph.h"
#include "qglview.h"
#include <QGLTexture2D>
#include <qglbuilder.h>
#include <QGLSphere>
#include <QGLMaterial>

class QGLAbstractScene;
class QGLSceneNode;

class ModelView : public QGLView
{
    Q_OBJECT
public:
    ModelView(QWindow *parent = 0);
    ~ModelView();

    QVector3DArray CalcArc(float R, float cx, float cy, float cz, QVector3D normal, int segments);\
    QVector3D CalcCoordinate(float lat, float lon);
    void drawArc(QVector3D startPoint, QVector3D endPoint, QGLPainter *painter);
    void drawSphere(QGLPainter *painter, QVector3D position);
    void drawGraph(QGLPainter *painter);
    void setGraph(Graph *a);
protected:
    void initializeGL(QGLPainter *painter);
    void paintGL(QGLPainter *painter);
private:
    QGLAbstractScene *m_scene;
    QGLTexture2D text;
    QGLSceneNode *sphere;
    QVector3D startPoint;
    Graph *workGraph;
    QGLMaterial *sphereMaterial;
    QGLTexture2D *sphereTexture;
    QImage *textureImage;
    QVector3DArray coordinats;
    QVector3DArray arcCoordinats;
    QMatrix4x4 rotateZ;
    QMatrix4x4 rotateY;
};

#endif
