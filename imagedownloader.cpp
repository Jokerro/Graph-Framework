#include "imagedownloader.h"


imageDownloader::imageDownloader(QObject *parent) :
    QObject(parent)
{
    // 1. Создаем QNetworkAccessManager и ожидаем от него сигнала finished

    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedSlot(QNetworkReply*)));
}

void imageDownloader::processRequest(QString URLaddress, QString n, Node* nd)
{
    // 2. осуществляем вызов нужного УРЛа
    ver = nd;
    name = n;
    QUrl url(URLaddress);
    QNetworkReply* reply = nam->get(QNetworkRequest(url));

}

// 3. Принимаем и обрабатываем ответ сервера
void imageDownloader::finishedSlot(QNetworkReply* reply)
{
    // Не произошло-ли ошибки?
    if (reply->error() == QNetworkReply::NoError)
    {
        // Читаем ответ от сервера
        QByteArray bytes = reply->readAll();
        QImage image = QImage::fromData(bytes);
        ver->setImagePhoto(image);
        ver->update();
        //image.save("images/"+name+".jpg");

    }
    // Произошла какая-то ошибка
    else
    {
        // обрабатываем ошибку
        qDebug() << reply->errorString();

    }
    delete reply;
}
