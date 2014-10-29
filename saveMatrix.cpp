#include "saveMatrix.h"

void saveMatrix::save(QString path){

    QFile newFile(path);
    newFile.open(QIODevice::WriteOnly | QIODevice::Text);

    /*QTextStream out(&newFile);
    out<<"hello World!";*/
    //вызовем функцию записи данных в готовый файл newFile

    newFile.close();

}
