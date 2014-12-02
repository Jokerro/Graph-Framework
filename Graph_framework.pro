#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T12:07:07
#
#-------------------------------------------------

QT       += core opengl network

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
    mainwindow.cpp \
    httprequest.cpp

HEADERS += \
    edge.h \
    graph.h \
    path.h \
    vertex.h \
    saveMatrix.h \
    mainwindow.h \
    colors.h \
    httprequest.h
