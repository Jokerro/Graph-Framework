#include "httprequest.h"

HttpRequest::HttpRequest(QObject *parent) :
    QObject(parent)
{
    // 1. Создаем QNetworkAccessManager и ожидаем от него сигнала finished

    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedSlot(QNetworkReply*)));
}

void HttpRequest::processRequest(QString URLaddress, Graph* gr, int id)
{
    // 2. осуществляем вызов нужного УРЛа
    graph = gr;
    uid = id;
    QUrl url(URLaddress);
    QNetworkReply* reply = nam->get(QNetworkRequest(url));

}

// 3. Принимаем и обрабатываем ответ сервера
void HttpRequest::finishedSlot(QNetworkReply* reply)
{
    // Не произошло-ли ошибки?
    if (reply->error() == QNetworkReply::NoError)
    {
        // Читаем ответ от сервера
        QByteArray bytes = reply->readAll();
        QString string(bytes);

        // Выводим ответ на экран

        QJsonParseError  parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(bytes, &parseError);
        if(parseError.error == QJsonParseError::NoError)
                {
                    if(jsonDoc.isObject())
                    {
                        QList<int> friends;
                        friends.append(uid);
                        //qDebug()<<jsonDoc.object().value("response").toArray().count();
                        for (int i=0; i<jsonDoc.object().value("response").toArray().count(); i++){
                            friends.append(jsonDoc.object().value("response").toArray().takeAt(i).toInt());
                        }
                        graph->setGraphFromVK(uid, friends);
                    }
                }else
                {
                    qDebug()<<parseError.errorString();
                }


        //qDebug() << string;

    }
    // Произошла какая-то ошибка
    else
    {
        // обрабатываем ошибку
        qDebug() << reply->errorString();

    }
    delete reply;
}

