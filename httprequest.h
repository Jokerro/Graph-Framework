#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QThread>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "graph.h"
#include "vertex.h"
#include "VKResponse.h"

class HttpRequest : public QObject
{
    Q_OBJECT
public:
    explicit HttpRequest(QObject *parent = 0);
    void processRequest(QString URLaddress, Graph* gr, int id, HttpRequest* req);
    Graph *graph;
    int uid;

signals:

public slots:
    void finishedSlot(QNetworkReply* reply);
private:
    QNetworkAccessManager* nam;
    HttpRequest *request;

};

#endif // HTTPREQUEST_H
