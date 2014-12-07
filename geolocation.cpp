#include "geolocation.h"
#include "vertex.h"

geoLocation::geoLocation(QObject *parent) :
    QObject(parent)
{
    // 1. Создаем QNetworkAccessManager и ожидаем от него сигнала finished

    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedSlot(QNetworkReply*)));
}

void geoLocation::processRequest(QString URLaddress, vertex* v)
{
    // 2. осуществляем вызов нужного УРЛа
    ver = v;
    QUrl url(URLaddress);
    QNetworkReply* reply = nam->get(QNetworkRequest(url));

}

// 3. Принимаем и обрабатываем ответ сервера
void geoLocation::finishedSlot(QNetworkReply* reply)
{
    // Не произошло-ли ошибки?
    if (reply->error() == QNetworkReply::NoError)
    {
        // Читаем ответ от сервера
        QByteArray bytes = reply->readAll();

        QJsonParseError  parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(bytes, &parseError);
        if(parseError.error == QJsonParseError::NoError)
                {
                    if(jsonDoc.isObject())
                    {
                        QStringList st = jsonDoc.object().value("response").toObject().value("GeoObjectCollection").toObject().
                                value("featureMember").toArray()[0].toObject().value("GeoObject").toObject().value("Point").
                                toObject().value("pos").toString().split(" ");
                        if (st.size() == 2)
                            ver->SetCoords(st[0].toFloat(0),st[1].toFloat(0));
                        else
                            ver->SetCoords(0,0);
                    }
                }else
                {
                    qDebug()<<parseError.errorString();
                }

    }
    // Произошла какая-то ошибка
    else
    {
        // обрабатываем ошибку
        qDebug() << reply->errorString();

    }
    delete reply;
}
