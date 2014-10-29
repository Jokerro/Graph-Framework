#include <iostream>
#include <stdlib.h>
#include <vector>
#include "graph.h"


using namespace std;

class Path:public Graph{
private:
    int StartPoint;
    int EndPoint;
public:
    Graph(){
    }
    ~Graph(){
    }
};
