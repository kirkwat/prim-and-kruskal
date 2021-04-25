//
// Created by watso on 4/25/2021.
//

#include "IndexedPriorityQueue.h"

IndexedPriorityQueue::IndexedPriorityQueue(){

}
IndexedPriorityQueue::IndexedPriorityQueue(int degree, int maxSize){
    d=max(2, degree);
    n=max(d+1, maxSize);

    im=new int[n];
    pm=new int[n];
    child=new int[n];
    parent=new int[n];
    values = new Edge[n];
    for (int i = 0; i < n; i++) {
        parent[i] = (i - 1) / d;
        child[i] = i * d + 1;
        pm[i] = im[i] = -1;
    }
}
bool IndexedPriorityQueue::isEmpty(){
    return sz == 0;
}
bool IndexedPriorityQueue::contains(int ki){
    return pm[ki] != -1;
}
int IndexedPriorityQueue::peekMinKeyIndex(){
    return im[0];
}
Edge IndexedPriorityQueue::peekMinValue() {
    return values[im[0]];
}
Edge IndexedPriorityQueue::pollMinValue(){
    Edge minValue=peekMinValue();
    deleteEdge(peekMinKeyIndex());
    return minValue;
}
void IndexedPriorityQueue::insert(int ki, Edge value){
    pm[ki] = sz;
    im[sz] = ki;
    values[ki] = value;
    swim(sz++);
}
Edge IndexedPriorityQueue::deleteEdge(int ki){
    int i = pm[ki];
    swap(i, --sz);
    sink(i);
    swim(i);
    Edge value = values[ki];
    //TODO FIX
    //values[ki] = null;
    pm[ki] = -1;
    im[sz] = -1;
    return value;
}
void IndexedPriorityQueue::decrease(int ki,Edge value){
    if (less(value, values[ki])) {
        values[ki] = value;
        swim(pm[ki]);
    }
}
void IndexedPriorityQueue::sink(int i){
    for (int j = minChild(i); j != -1; ) {
        swap(i, j);
        i = j;
        j = minChild(i);
    }
}
void IndexedPriorityQueue::swim(int i){
    while (less(i, parent[i])) {
        swap(i, parent[i]);
        i = parent[i];
    }
}
int IndexedPriorityQueue::minChild(int i){
    int index = -1, from = child[i], to = min(sz, from + d);
    for (int j = from; j < to; j++) if (less(j, i)) index = i = j;
    return index;
}
void IndexedPriorityQueue::swap(int i, int j){
    pm[im[j]] = i;
    pm[im[i]] = j;
    int tmp = im[i];
    im[i] = im[j];
    im[j] = tmp;
}
//TODO OPTIMIZE
bool IndexedPriorityQueue::less(int i, int j){
    return values[im[i]]<values[im[j]];
}
//TODO OPTIMIZE
bool IndexedPriorityQueue::less(Edge e1, Edge e2){
    return e1<e2;
}