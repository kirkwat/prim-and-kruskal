//Kirk Watson - 47876885 - CS3353
#ifndef S21_PA04_KWATSON_INDEXEDPRIORITYQUEUE_H
#define S21_PA04_KWATSON_INDEXEDPRIORITYQUEUE_H

#include <algorithm>
#include "Edge.h"

using namespace std;

//This class implements an indexed priority queue using a minimum indexed d-ary heap.
class IndexedPriorityQueue {
private:
    int currSize;           //current num of elements in heap
    int capacity;           //max num of elements in heap
    int degree;             //degree of nodes in heap
    int* child;             //loop up arrays to track child indexes of each node
    int* parent;            //loop up arrays to track parent indexes of each node
    int* priorityMap;       //position map for values
    int* inverseMap;        //inverse map for values, used for minimum index
    Edge* values;           //holds edge values for each key

    void sink(int);
    void swim(int);
    int minChild(int);
    void swap(int, int);

public:
    IndexedPriorityQueue();
    IndexedPriorityQueue(int,int);

    bool isEmpty();
    bool contains(int);
    int peekMinKey();
    Edge peekMinVal();
    Edge pollMinVal();
    void insert(int, Edge);
    Edge deleteVal(int);
    void decrease(int,Edge);
};


#endif //S21_PA04_KWATSON_INDEXEDPRIORITYQUEUE_H
