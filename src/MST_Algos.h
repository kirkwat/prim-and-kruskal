//Kirk Watson - 47876885 - CS3353
#ifndef S21_PA04_KWATSON_MST_ALGOS_H
#define S21_PA04_KWATSON_MST_ALGOS_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <queue>
#include "Graph.h"
#include "Edge.h"
#include "IndexedPriorityQueue.h"
#include "UnionFind.h"

using namespace std;

//This class is the launcher of the program and contains the two MST algorithms implemented in this program.
//The first algorithm is Eager Prim's algorithm using an indexed priority queue data structure.
//The second algorith is Kruskal's algorithm using a union-find data structure.
class MST_Algos {
private:
    Graph graph;                //graph read from file
    priority_queue<Edge> pq;    //priority queue used for kruskals algo, filled while reading algo
    int nodes;                  //number of nodes in graph

public:
    MST_Algos();

    void readGraph(const char*);
    void prim();
    void kruskal();
    void testGraph();
};


#endif //S21_PA04_KWATSON_MST_ALGOS_H
