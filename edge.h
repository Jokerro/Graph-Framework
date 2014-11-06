#ifndef EDGE_H
#define EDGE_H

using namespace std;

class edge{
private:
    int id;
    int weight;
    int capacity;
    int streamValue;
public:
    edge(){ id=0; weight = 0; capacity=0; streamValue=0;}
    ~edge(){}
};

#endif
