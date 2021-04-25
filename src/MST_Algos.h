//Kirk Watson - 47876885 - CS3353
#ifndef S21_PA04_KWATSON_MST_ALGOS_H
#define S21_PA04_KWATSON_MST_ALGOS_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "Graph.h"
#include "IndexedPriorityQueue.h"
#include "Edge.h"

using namespace std;

//This class is the launcher of the program and contains the two MST algorithms implemented in this program.
//The first algorithm is Eager Prim's algorithm using an indexed priority queue data structure.
//The second algorith is Kruskal's algorithm using a union-find data structure.
class MST_Algos {
private:
    Graph graph;    //graph read from file
    int nodes;      //number of nodes in graph

public:
    MST_Algos();
    void readGraph(const char*);
    void prim();
    void testGraph();
};


#endif //S21_PA04_KWATSON_MST_ALGOS_H
