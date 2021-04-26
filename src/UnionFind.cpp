//Kirk Watson - 47876885 - CS3353
#include "UnionFind.h"
//default constructor
UnionFind::UnionFind(){
    unionSize=nullptr;
    connections=nullptr;
}
//overloaded constructor
//arguments - number of nodes
UnionFind::UnionFind(int num){
    unionSize = new int[num];
    connections = new int[num];
    //initialize connections and union size
    for (int x = 0; x < num; x++) {
        //node is connected to itself
        connections[x] = x;
        unionSize[x] = 1;
    }
}
//finds connection for requested node
//arguments - requested node
int UnionFind::find(int node){
    int root = node;
    //find root of union
    while (root != connections[root]){
        root = connections[root];
    }
    //compress paths in union for constant time complexity
    while (node != root) {
        int next = connections[node];
        connections[node] = root;
        node = next;
    }
    return root;
}
//returns true if nodes are in the same union
//arguments - first node, second node
bool UnionFind::connected(int node1, int node2){
    return find(node1) == find(node2);
}
//returns size of union for given node
//arguments - requested node
int UnionFind::size(int node){
    return unionSize[find(node)];
}
//connect nodes to same union
//arguments - first node, second node
void UnionFind::unify(int node1, int node2){
    //get roots of nodes
    int root1 = find(node1);
    int root2 = find(node2);
    //return if nodes are in same union
    if (root1 == root2){
        return;
    }
    //merge smaller group into larger group
    if (unionSize[root1] < unionSize[root2]) {
        unionSize[root2] += unionSize[root1];
        connections[root1] = root2;
    }
    else {
        unionSize[root1] += unionSize[root2];
        connections[root2] = root1;
    }
}