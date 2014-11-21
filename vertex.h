#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>

using namespace std;

class vertex{
    private:
        int id;
        int degree;
        int pos_x;
        int pos_y;
        bool painted;
    public:
        vertex(int iid){id=iid; degree=0; pos_x=0; pos_y=0; painted=false;}
        vertex(int i_id, int i_degree, int i_x, int i_y) :
            id(i_id), degree(i_degree), pos_x(i_x), pos_y(i_y), painted(false)
        {}
        int GetId(){return id;}
        ~vertex(){}
        bool isPainted(){return painted;}
        void markAsPainted() {painted=true;}
        void noPaint(){painted=false;}
        int getX(){return pos_x;}
        int getY(){return pos_y;}

        void setPosition(int X, int Y){pos_x=X; pos_y=Y;}
};

#endif
