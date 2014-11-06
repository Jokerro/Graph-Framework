#include "saveMatrix.h"

int saveMatrix::save(QString path, Graph* graph){

    QFile* file = new QFile(path);
    if (file->open(QIODevice::WriteOnly | QIODevice::Text)){

        saveMatrix::matrixToStr(graph, file);

        file->close();

        return 0;

    }else{

        return 1;

    }


    return 0;

}

void saveMatrix::matrixToStr(Graph* graph, QFile* file){

    QTextStream out(file);

    for(int i=0; i<graph->getVertexCount(); i++){

       bool flag=false;
       out<<(i+1)<<":";
       for(int j=0; j<graph->getVertexCount(); j++){

           if (graph->getAdjecensyMatrixElem(i,j)!=0)
               for (int temp=0; temp<graph->getAdjecensyMatrixElem(i,j); temp++)
               if (flag)
                    out<<","<<(j+1);
               else{
                    out<<(j+1);
                    flag=true;
               }

       }
       if (i!=graph->getVertexCount()-1)
                  out<<";\n";

    }


}
