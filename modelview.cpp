#include "modelview.h"
#include "qglabstractscene.h"
#include "qglabstractmaterial.h"
#include "qglmaterial.h"
#include <QGLTexture2D>
#include <qimage.h>
#include <QColor>
ModelView::~ModelView()
{
    delete m_scene;
}


void ModelView::initializeGL(QGLPainter *painter)
{
    Q_UNUSED(painter);

    QGLMaterial *mat=new QGLMaterial();
    text.setImage(QImage("E:\\Qt\\text.png"));
    mat->setTexture(&text);
    m_scene = QGLAbstractScene::loadScene("E:\\Qt\\Earth.obj");
}

void ModelView::paintGL(QGLPainter *painter)
{
     painter->setStandardEffect(QGL::FlatReplaceTexture2D);
     painter->glActiveTexture(GL_TEXTURE0);
    // painter->clearAttributes();
    // painter->setVertexAttribute(QGL::Position, positions);
    // painter->setVertexAttribute(QGL::TextureCoord0, texCoords);
    // painter->setVertexAttribute(QGL::CustomVertex0, gradientCoords);
     //setAlphaValue(&painter, 1.0f);
     painter->update();
     text.bind();
     QGLSceneNode *o = m_scene->mainNode();
     o->draw(painter);
}
