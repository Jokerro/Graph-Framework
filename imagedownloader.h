#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H


#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QThread>
#include <QImage>

class vertex;

class ImagesDownloader : public QObject
{
    Q_OBJECT
public:
    explicit ImagesDownloader(QObject *parent = 0);
    void addImagetoDownload(vertex* vert);
    bool isFinished(){return finished;}

signals:

public slots:
    void finishedSlot(QNetworkReply* reply);
private:
    QNetworkAccessManager* nam;
    QList<vertex*> vertexes;
    bool finished;
    ImagesDownloader* subDownloader;

};



#endif // IMAGEDOWNLOADER_H
