//Kirk Watson - 47876885 - CS3353
#ifndef S21_PA04_KWATSON_GRAPH_H
#define S21_PA04_KWATSON_GRAPH_H

#include <vector>
#include <iostream>//TODO delete
#include "Edge.h"

using namespace std;

//This class is the container of the graph. It holds all edges and maintains their connections.
class Graph {
private:
    vector<vector<Edge>> graph;     //store edges in undirected graph using an adjacency list with vectors
public:
    Graph();
    Graph(int);

    void AddEdge(int, int, int);
    vector<Edge> at(int);
    void print();//TODO delete
};


#endif //S21_PA04_KWATSON_GRAPH_H
