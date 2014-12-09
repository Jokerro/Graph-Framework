#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T12:07:07
#
#-------------------------------------------------

QT       += core opengl network widgets 3dquick
QT       -= gui

#QMAKE_LIBS+=-static -lgomp -lpthread

LIBS += -fopenmp
QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS += -fopenmp

TARGET = Graph_framework
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    saveMatrix.cpp \
    graph.cpp \
    httprequest.cpp \
    modelview.cpp \
    shaders.cpp \
    edge.cpp \
    graphwidget.cpp \
    node.cpp \
    mainwindow.cpp \
    imagedownloader.cpp \
    uimainwindow.cpp \
    geolocation.cpp

HEADERS += \
    edge.h \
    graph.h \
    path.h \
    vertex.h \
    saveMatrix.h \
    httprequest.h \
    modelview.h \
    shaders.h \
    graphwidget.h \
    node.h \
    mainwindow.h \
    imagedownloader.h \
    uimainwindow.h \
    VKResponse.h \
    geolocation.h
