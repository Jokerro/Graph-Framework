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

        }
        ~vertex(){}

        int GetId(){return id;}
        QString getPhotoUrl(){return photoUrl;}
        QString getCountry(){return country;}
        Node* getNode(){return node;}
        int GetUserId(){return user_id;}
        int setID(int iid){this->id=iid;}
        void SetCoords(float lat, float lon){latitude = lat; longitude = lon;}
};

#endif
