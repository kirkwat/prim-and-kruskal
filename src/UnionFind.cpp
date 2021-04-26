//
// Created by watso on 4/25/2021.
//

#include "UnionFind.h"
//default constructor
UnionFind::UnionFind(){
    sz=nullptr;
    id=nullptr;
}
//overloaded constructor
//arguments TODO
UnionFind::UnionFind(int n){
    id = new int[n];
    sz = new int[n];
    for (int i = 0; i < n; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}

int UnionFind::find(int p){
    int root = p;
    while (root != id[root]) root = id[root];
    // Path compression
    while (p != root) {
        int next = id[p];
        id[p] = root;
        p = next;
    }
    return root;
}
bool UnionFind::connected(int p, int q){
    return find(p) == find(q);
}
int UnionFind::size(int p){
    return sz[find(p)];
}
void UnionFind::unify(int p, int q){
    int root1 = find(p);
    int root2 = find(q);
    if (root1 == root2) return;
    if (sz[root1] < sz[root2]) {
        sz[root2] += sz[root1];
        id[root1] = root2;
    } else {
        sz[root1] += sz[root2];
        id[root2] = root1;
    }
}