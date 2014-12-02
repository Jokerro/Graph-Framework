#ifndef MODELVIEW_H
#define MODELVIEW_H

#include "qglview.h"
#include <QGLTexture2D>
class QGLAbstractScene;
class QGLSceneNode;

class ModelView : public QGLView
{
    Q_OBJECT
public:
    ModelView(QWindow *parent = 0) : QGLView(parent) {}
    ~ModelView();

protected:
    void initializeGL(QGLPainter *painter);
    void paintGL(QGLPainter *painter);

private:
    QGLAbstractScene *m_scene;
    QGLTexture2D text;
};

#endif
