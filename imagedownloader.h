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

class vertex;

class ImagesDownloader : public QObject
{
    Q_OBJECT
public:
<<<<<<< HEAD
    explicit imageDownloader(QObject *parent = 0);
    void processRequest(QString URLaddress, QString n, Node* v);
    QString name;
=======
    explicit ImagesDownloader(QObject *parent = 0);
    void addImagetoDownload(vertex* vert);
    bool isFinished(){return finished;}

>>>>>>> origin/master
signals:

public slots:
    void finishedSlot(QNetworkReply* reply);
private:
    QNetworkAccessManager* nam;
<<<<<<< HEAD
    Node* ver;
=======
    QList<vertex*> vertexes;
    bool finished;
    ImagesDownloader* subDownloader;
>>>>>>> origin/master

};



#endif // IMAGEDOWNLOADER_H
