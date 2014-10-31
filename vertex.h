#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>

using namespace std;

class vertex{
    private:
        int id;
        int degree;
    public:
        vertex(){id=0; degree=0;}
        ~vertex(){}
};

#endif
