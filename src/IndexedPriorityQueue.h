//
// Created by watso on 4/25/2021.
//

#ifndef S21_PA04_KWATSON_INDEXEDPRIORITYQUEUE_H
#define S21_PA04_KWATSON_INDEXEDPRIORITYQUEUE_H

#include <algorithm>
#include "Edge.h"

using namespace std;

class IndexedPriorityQueue {
private:
    int sz;
    int n;
    int d;
    int* child;
    int* parent;
    int* pm;
    int* im;
    Edge* values;

public:
    IndexedPriorityQueue();
    IndexedPriorityQueue(int,int);
    bool isEmpty();
    bool contains(int);
    int peekMinKeyIndex();
    Edge peekMinValue();
    Edge pollMinValue();
    void insert(int, Edge);
    Edge deleteEdge(int);
    void decrease(int,Edge);
    void sink(int);
    void swim(int);
    int minChild(int);
    void swap(int, int);
    bool less(int, int);
    bool less(Edge, Edge);
};


#endif //S21_PA04_KWATSON_INDEXEDPRIORITYQUEUE_H
