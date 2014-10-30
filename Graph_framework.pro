#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T12:07:07
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Graph_framework
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    saveMatrix.cpp \
    graph.cpp

HEADERS += \
    edge.h \
    graph.h \
    path.h \
    vertex.h \
    saveMatrix.h
