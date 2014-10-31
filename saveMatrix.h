#ifndef SAVEMATRIX_H
#define SAVEMATRIX_H
#include <QFile>
#include <QString>
#include <QTextStream>
#include "graph.h"

class saveMatrix{

    public: static int save(QString, Graph*);

    private: static void matrixToStr(Graph*, QFile*);

};


#endif // SAVEMATRIX_H
