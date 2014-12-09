#include "geolocation.h"
#include "vertex.h"

GeoLocation::GeoLocation(QObject *parent) :
    QObject(parent)
{
    // 1. Создаем QNetworkAccessManager и ожидаем от него сигнала finished
    finished = true;
    request = "http://geocode-maps.yandex.ru/1.x/?format=json&geocode=";
    numberOfres = "&result=1";
    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedSlot(QNetworkReply*)));
}

void GeoLocation::addGeotoDetect(vertex* v)
{
    // 2. осуществляем вызов нужного УРЛа
    vertexes.append(v);
    if(finished){
        QUrl url(request+v->getCountry()+numberOfres);
        finished = false;
        QNetworkReply* reply = nam->get(QNetworkRequest(url));
    }

}

// 3. Принимаем и обрабатываем ответ сервера
void GeoLocation::finishedSlot(QNetworkReply* reply)
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
                            vertexes[0]->SetCoords(st[0].toFloat(0),st[1].toFloat(0));
                        else
                            vertexes[0]->SetCoords(0,0);
                    }
                }else
                {
                    qDebug()<<parseError.errorString();
                }
        vertexes.removeAt(0);
        if (vertexes.size()>0)
            nam->get(QNetworkRequest(request+vertexes[0]->getCountry()+numberOfres));
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
        nam->get(QNetworkRequest(request+vertexes[0]->getCountry()+numberOfres));
    }
    delete reply;
    //delete ver->getHttpGeo();
}
