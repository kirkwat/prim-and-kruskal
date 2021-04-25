
#include "Graph.h"
//default constructor
Graph::Graph(){}
//overloaded constructor with number of vertices
Graph::Graph(int v){
    //add a vector for every vertex
    for(int x=0;x<=v;x++){
        graph.push_back(vector<Edge>());
    }
}
//add undirected edge
void Graph::AddEdge(int from, int to, int weight){
    //add directed edge going both directions
    graph[from].push_back(Edge(from, to, weight));
    graph[to].push_back(Edge(to, from, weight));
}
//get vector of connected edges for requested vertex
vector<Edge> Graph::at(int i){
    return graph[i];
}
//display graph
void Graph::print(){
    int counter=0;
    for(int x=0;x<graph.size();x++){
        for(int y=0;y<graph[x].size();y++){
            cout<<graph[x][y].getTo()<<":"<<graph[x][y].getFrom()<<"-"<<graph[x][y].getCost()<<endl;
            counter++;
        }
        cout<<endl;
    }
    cout<<"counter: "<<counter<<endl;
}