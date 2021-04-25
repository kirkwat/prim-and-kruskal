//
// Created by watso on 4/24/2021.
//

#include "Graph.h"

Graph::Graph(){

}
Graph::Graph(int e){
    for(int x=0;x<=e;x++){
        graph.push_back(vector<Edge>());
    }
}
void Graph::AddEdge(int from, int to, int weight){

}