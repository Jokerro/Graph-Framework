#ifndef GEOLOCATION_H
#define GEOLOCATION_H


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

class vertex;

class geoLocation : public QObject
{
    Q_OBJECT
public:
    explicit geoLocation(QObject *parent = 0);
    void processRequest(QString URLaddress, vertex* v);

signals:

public slots:
    void finishedSlot(QNetworkReply* reply);
private:
    QNetworkAccessManager* nam;
    vertex* ver;
};



#endif // GEOLOCATION_H
