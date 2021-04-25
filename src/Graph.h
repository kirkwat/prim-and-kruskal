
#ifndef S21_PA04_KWATSON_GRAPH_H
#define S21_PA04_KWATSON_GRAPH_H

#include <vector>
#include <iostream>
#include "Edge.h"

using namespace std;

class Graph {
private:
    vector<vector<Edge>> graph;
public:
    Graph();
    Graph(int);
    void AddEdge(int, int, int);
    vector<Edge> at(int);
    void print();
};


#endif //S21_PA04_KWATSON_GRAPH_H
