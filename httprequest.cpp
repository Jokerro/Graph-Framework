#include "httprequest.h"

HttpRequest::HttpRequest(QObject *parent) :
    QObject(parent)
{
    // 1. Создаем QNetworkAccessManager и ожидаем от него сигнала finished

    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedSlot(QNetworkReply*)));
}

void HttpRequest::processRequest(QString URLaddress, Graph* gr, int id, HttpRequest *req)
{
    // 2. осуществляем вызов нужного УРЛа
    graph = gr;
    uid = id;
    request = req;
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

        // Выводим ответ на экран

        QJsonParseError  parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(bytes, &parseError);
        if(parseError.error == QJsonParseError::NoError)
                {
                    if(jsonDoc.isObject())
                    {
                        if(jsonDoc.object().value("response").isObject()){
                            QList<VKResponse> friends;
                            VKResponse temp_friend;
                            temp_friend.id = uid;
                            friends.append(temp_friend);
                            //qDebug()<<jsonDoc.object().value("response").toArray().count();
                            for (int i=0; i<jsonDoc.object().value("response").toObject().value("count").toInt(); i++){
                                temp_friend.id = jsonDoc.object().value("response").toObject().value("items").toArray().takeAt(i).toObject().value("id").toInt();
                                temp_friend.country = jsonDoc.object().value("response").toObject().value("items").toArray().takeAt(i).toObject().value("country").toObject().value("title").toString();
                                temp_friend.city = jsonDoc.object().value("response").toObject().value("items").toArray().takeAt(i).toObject().value("city").toObject().value("title").toString();
                                temp_friend.first_name = jsonDoc.object().value("response").toObject().value("items").toArray().takeAt(i).toObject().value("first_name").toString();
                                temp_friend.last_name = jsonDoc.object().value("response").toObject().value("items").toArray().takeAt(i).toObject().value("last_name").toString();
                                temp_friend.photo_50 = jsonDoc.object().value("response").toObject().value("items").toArray().takeAt(i).toObject().value("photo_100").toString();
                                friends.append(temp_friend);
                            }
                            graph->setGraphFromVK(uid, friends);
                        }else if(jsonDoc.object().value("response").isArray()){
                            VKResponse centralUser;
                            centralUser.id=uid;
                            centralUser.first_name = jsonDoc.object().value("response").toArray()[0].toObject().value("first_name").toString();
                            centralUser.last_name = jsonDoc.object().value("response").toArray()[0].toObject().value("last_name").toString();
                            centralUser.photo_50 = jsonDoc.object().value("response").toArray()[0].toObject().value("photo_100").toString();
                            centralUser.country = jsonDoc.object().value("response").toArray()[0].toObject().value("country").toObject().value("title").toString();
                            centralUser.city = jsonDoc.object().value("response").toArray()[0].toObject().value("city").toObject().value("title").toString();
                            graph->addVertexFromVK(centralUser);
                            QString str="http://api.vk.com/method/friends.get?user_id="+QString::number(uid)+"&fields=photo_100,country,city&v=5.27";
                            request->processRequest(str, graph, uid,request);
                        }
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

