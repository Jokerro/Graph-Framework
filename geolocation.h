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

class GeoLocation : public QObject
{
    Q_OBJECT
public:
    explicit GeoLocation(QObject *parent = 0);
    void addGeotoDetect(vertex* v);
    bool isFinished(){return finished;}

signals:

public slots:
    void finishedSlot(QNetworkReply* reply);
private:
    QNetworkAccessManager* nam;
    QList<vertex*> vertexes;
    bool finished;
    QString request;
    QString numberOfres;
};



#endif // GEOLOCATION_H
