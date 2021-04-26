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
        graph.push_back(vector<Edge>());
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
//display graph
void Graph::print(){//TODO delete
    int counter=0;
    for(int x=0;x<graph.size();x++){
        for(int y=0;y<graph[x].size();y++){
            cout<<graph[x][y].getFrom()<<":"<<graph[x][y].getTo()<<"-"<<graph[x][y].getWeight()<<endl;
            counter++;
        }
        cout<<endl;
    }
    cout<<"total edges: "<<counter<<endl<<endl;
}