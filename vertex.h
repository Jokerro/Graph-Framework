#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include "node.h"
#include "VKResponse.h"
#include "imagedownloader.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

using namespace std;

class vertex{
    private:
        int id;
        QString first_name;
        QString last_name;
        QString country;
        QString city;
        QString photo_50;
        imageDownloader *req;
        Node *node;
    public:
        vertex(int iid){id=iid;}
        vertex(int iid, Node *nd){id=iid; node=nd;}
        vertex(VKResponse resp, Node *nd):id(resp.id),first_name(resp.first_name),last_name(resp.last_name),
                                        country(resp.country),city(resp.city),photo_50(resp.photo_50),node(nd){
            req = new imageDownloader;

            req->processRequest(resp.photo_50,QString::number(resp.id));
        }
        ~vertex(){}

        int GetId(){return id;}
        Node* getNode(){return node;}

};

#endif
