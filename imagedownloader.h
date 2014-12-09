#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H


#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QThread>
#include <QImage>
#include "node.h"

class imageDownloader : public QObject
{
    Q_OBJECT
public:
    explicit imageDownloader(QObject *parent = 0);
    void processRequest(QString URLaddress, QString n, Node* v);
    QString name;
signals:

public slots:
    void finishedSlot(QNetworkReply* reply);
private:
    QNetworkAccessManager* nam;
    Node* ver;

};



#endif // IMAGEDOWNLOADER_H
