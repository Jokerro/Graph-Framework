#include <QCoreApplication>
#include "path.h"
#include "saveMatrix.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Graph temp;
    temp.init(4,7);


    return a.exec();
}
