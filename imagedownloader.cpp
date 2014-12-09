#include "imagedownloader.h"
#include "vertex.h"

ImagesDownloader::ImagesDownloader(QObject *parent) :
    QObject(parent)
{
    // 1. Создаем QNetworkAccessManager и ожидаем от него сигнала finished
    finished = true;
    subDownloader = NULL;
    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedSlot(QNetworkReply*)));
}

void ImagesDownloader::addImagetoDownload(vertex* vert)
{
    // 2. осуществляем вызов нужного УРЛа
   /* if (vertexes.size()>20){
        if(subDownloader == NULL)
            subDownloader = new ImagesDownloader();
        subDownloader->addImagetoDownload(vert);
    }else{*/
        vertexes.append(vert);
        if(finished){
            QUrl url(vert->getPhotoUrl());
            finished = false;
            QNetworkReply* reply = nam->get(QNetworkRequest(url));
        }


}

// 3. Принимаем и обрабатываем ответ сервера
void ImagesDownloader::finishedSlot(QNetworkReply* reply)
{
    // Не произошло-ли ошибки?
    if (reply->error() == QNetworkReply::NoError)
    {
        // Читаем ответ от сервера
        QByteArray bytes = reply->readAll();
        QImage image = QImage::fromData(bytes);
        vertexes[0]->getNode()->setImagePhoto(image);
        vertexes[0]->getNode()->update();
        image.save("images/"+QString::number(vertexes[0]->GetUserId())+".jpg");
        vertexes.removeAt(0);
        if (vertexes.size()>0)
            nam->get(QNetworkRequest(vertexes[0]->getPhotoUrl()));
        else
            finished = true;

    }
    // Произошла какая-то ошибка
    else
    {
        // обрабатываем ошибку
        qDebug() << reply->errorString();
        if (reply->error()!=203)
            vertexes.append(vertexes[0]);
        vertexes.removeAt(0);
        nam->get(QNetworkRequest(vertexes[0]->getPhotoUrl()));
    }

    delete reply;
  //  delete ver->getHttpImg();
}
