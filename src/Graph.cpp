//Kirk Watson - 47876885 - CS3353
#include "Graph.h"
//default constructor
Graph::Graph(){
}
//overloaded constructor with number of vertices
//arguments - number of vertices
Graph::Graph(int v){
    //add a vector for every vertex
    for(int x=0;x<=v;x++){
        graph.emplace_back(vector<Edge>());
    }
}
//add undirected edge
//arguments - from, to, weight
void Graph::AddEdge(int from, int to, int weight){
    //add directed edge going both directions
    graph[from].push_back(Edge(to, from, weight));
    graph[to].push_back(Edge(from, to, weight));
}
//get vector of connected edges for requested vertex
//arguments - starting vertex index
vector<Edge> Graph::at(int index){
    return graph[index];
}