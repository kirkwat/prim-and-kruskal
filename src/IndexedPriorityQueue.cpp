//
// Created by watso on 4/25/2021.
//

#include "IndexedPriorityQueue.h"

IndexedPriorityQueue::IndexedPriorityQueue(int degree, int maxSize){
    d=max(2, degree);
    n=max(d+1, maxSize);

    im=new int[n];
    pm=new int[n];
    child=new int[n];
    parent=new int[n];
    //TODO fix
    //values = new Object[N];
    for (int i = 0; i < n; i++) {
        parent[i] = (i - 1) / d;
        child[i] = i * d + 1;
        pm[i] = im[i] = -1;
    }
}