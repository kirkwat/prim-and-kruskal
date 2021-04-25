//
// Created by watso on 4/24/2021.
//

#ifndef S21_PA04_KWATSON_MST_ALGOS_H
#define S21_PA04_KWATSON_MST_ALGOS_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"

using namespace std;

class MST_Algos {
private:
    Graph graph;
    int nodes;
public:
    MST_Algos();
    void readGraph(const char*);
    void prim();
};


#endif //S21_PA04_KWATSON_MST_ALGOS_H
