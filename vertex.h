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
        //////
        int user_id;
        /////
        QString first_name;
        QString last_name;
        QString country;
        QString city;
        QString photoUrl;
        float latitude;
        float longitude;
        //ImagesDownloader *req;
        Node *node;

    public:
        vertex(int iid){id=iid;}
<<<<<<< HEAD
        vertex(int iid, Node *nd){id=iid; node=nd;}
        vertex(VKResponse resp, Node *nd):id(resp.id),first_name(resp.first_name),last_name(resp.last_name),
                                        country(resp.country),city(resp.city),photo_50(resp.photo_50),node(nd){
            req = new imageDownloader;
            req->processRequest(resp.photo_50,QString::number(resp.id), nd);

=======
        vertex(int iid, Node *nd){
                               ///////////////////
                                user_id=iid;
                                /////////////
                                  node=nd;
                                   //////////////
                                  node->setTrueId(iid);
                                  ///
                                    }
        vertex(VKResponse resp, Node *nd):/* !!*/ user_id(resp.id),first_name(resp.first_name),last_name(resp.last_name),
                                        country(resp.country),city(resp.city),photoUrl(resp.photoUrl),node(nd){
            node->setId(resp.id);
            node->setTrueId(user_id);
>>>>>>> origin/master

        }
        ~vertex(){}
       float getLat(){return latitude;}
       float getLon(){return longitude;}
        int GetId(){return id;}
        QString getPhotoUrl(){return photoUrl;}
        QString getCountry(){return country;}
        Node* getNode(){return node;}
<<<<<<< HEAD
        void calcCoords(){
            if(country!=""){
                reqgeo = new geoLocation;
                reqgeo->processRequest("http://geocode-maps.yandex.ru/1.x/?format=json&geocode="+country+","+city+"&results=1", this);
            }else
                SetCoords(0,0);
        }

=======
        int GetUserId(){return user_id;}
        int setID(int iid){this->id=iid;}
>>>>>>> origin/master
        void SetCoords(float lat, float lon){latitude = lat; longitude = lon;}
};

#endif
