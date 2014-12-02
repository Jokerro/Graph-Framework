/*#include "shaders.h"

static char const VertexShader[] =
     "attribute highp vec4 qt_Vertex;\n"
     "attribute highp vec4 qt_MultiTexCoord0;\n"
     "attribute highp float qt_Custom0;\n"
     "uniform mediump mat4 qt_ModelViewProjectionMatrix;\n"
     "varying highp vec4 qt_TexCoord0;\n"
     "varying highp float qGradCtrl;\n"
     "void main(void)\n"
     "{\n"
     "    gl_Position = qt_ModelViewProjectionMatrix * qt_Vertex;\n"
     "    qt_TexCoord0 = qt_MultiTexCoord0;\n"
     "    qGradCtrl = qt_Custom0;\n"
     "}\n";

 static char const FragmentShader[] =
     "uniform sampler2D qt_Texture0;\n"
     "uniform mediump float alphaValue;\n"
     "varying highp vec4 qt_TexCoord0;\n"
     "varying highp float qGradCtrl;\n"
     "void main(void)\n"
     "{\n"
     "    mediump vec4 col = texture2D(qt_Texture0, qt_TexCoord0.st);\n"
     "    mediump vec4 gradcol = texture2D(qt_Texture1, vec2(qGradCtrl, qt_TexCoord0.t));\n"
     "    gl_FragColor = vec4((col * gradcol).xyz, alphaValue);\n"
     "}\n";

Shaders::Shaders()
 {
     setVertexShader(VertexShader);
     setFragmentShader(FragmentShader);
 }

Shaders::~Shaders()
 {
 }

 void Shaders::setAlphaValue(GLfloat value)
 {
     program()->setUniformValue("alphaValue", value);
 }*/
