//
// Created by watso on 4/25/2021.
//

#ifndef S21_PA04_KWATSON_INDEXEDPRIORITYQUEUE_H
#define S21_PA04_KWATSON_INDEXEDPRIORITYQUEUE_H

#include <algorithm>

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
    //TODO fix
    //Object[] values;

public:
    IndexedPriorityQueue(int,int);
    int getSize();
    bool isEmpty();
    bool contains(int);
    int peekMinKeyIndex();
    pollMinKeyIndex();
    E
};


#endif //S21_PA04_KWATSON_INDEXEDPRIORITYQUEUE_H
