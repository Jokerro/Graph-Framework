#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include "node.h"
#include "VKResponse.h"
#include "imagedownloader.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QDebug>
#include "geolocation.h"

using namespace std;

class vertex{
    private:
        int id;
        QString first_name;
        QString last_name;
        QString country;
        QString city;
        QString photoUrl;
        float latitude;
        float longitude;
        //ImagesDownloader *req;
        GeoLocation *reqgeo;
        Node *node;

    public:
        vertex(int iid){id=iid;}
        vertex(int iid, Node *nd){id=iid; node=nd;}
        vertex(VKResponse resp, Node *nd):id(resp.id),first_name(resp.first_name),last_name(resp.last_name),
                                        country(resp.country),city(resp.city),photoUrl(resp.photoUrl),node(nd){
            //req = new ImagesDownloader;
            //req->processRequest(resp.photoUrl, this);

            /*if(resp.country!=""){
                reqgeo = new geoLocation;
                reqgeo->processRequest("http://geocode-maps.yandex.ru/1.x/?format=json&geocode="+country+"&results=1", this);
            }else
                SetCoords(0,0);*/

        }
        ~vertex(){}

        int GetId(){return id;}
        QString getPhotoUrl(){return photoUrl;}
        QString getCountry(){return country;}
        Node* getNode(){return node;}
        GeoLocation* getHttpGeo(){return reqgeo;}
        void SetCoords(float lat, float lon){latitude = lat; longitude = lon;}
};

#endif
