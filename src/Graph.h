//
// Created by watso on 4/24/2021.
//

#ifndef S21_PA04_KWATSON_GRAPH_H
#define S21_PA04_KWATSON_GRAPH_H

#include <vector>

using namespace std;

class Edge{
public:
    int to, from, cost;
    Edge(int t, int f,  int c){
        to=t;
        from=f;
        cost=c;
    }
};

class Graph {
private:
    vector<vector<Edge>> graph;
public:
    Graph();
    void AddEdge(int, int, int);
};


#endif //S21_PA04_KWATSON_GRAPH_H
