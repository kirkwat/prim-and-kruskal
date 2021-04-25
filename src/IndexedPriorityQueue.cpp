//Kirk Watson - 47876885 - CS3353
#include "IndexedPriorityQueue.h"
//default constructor
IndexedPriorityQueue::IndexedPriorityQueue(){}
//overloaded constructor with degree and capacity
//arguments - degree, max size
IndexedPriorityQueue::IndexedPriorityQueue(int d, int m){
    //initialize values
    currSize=0;                         //current num of elements
    degree=max(2, d);                   //degree of nodes in heap
    capacity=max(degree+1, m);          //capacity
    //initialize arrays
    inverseMap=new int[capacity];       //index map
    priorityMap=new int[capacity];      //position map
    child=new int[capacity];            //tracks child indexes of each node
    parent=new int[capacity];           //tracks parent indexes of each node
    values = new Edge[capacity];        //holds edge values for each key
    //initialize values
    for (int x = 0; x < capacity; x++) {
        //use degree to create indexes
        parent[x] = (x - 1) / degree;
        child[x] = x * degree + 1;
        //set to empty
        priorityMap[x] = inverseMap[x] = -1;
    }
}
//returns true if priority queue is empty
bool IndexedPriorityQueue::isEmpty(){
    return currSize == 0;
}
//returns true if priority queue contains a value at the key index
//arguments - key index
bool IndexedPriorityQueue::contains(int keyIndex){
    return priorityMap[keyIndex] != -1;
}
//returns index of min value
int IndexedPriorityQueue::peekMinKey(){
    return inverseMap[0];
}
//returns min value
Edge IndexedPriorityQueue::peekMinVal() {
    return values[inverseMap[0]];
}
//get min value and remove from queue
Edge IndexedPriorityQueue::pollMinVal(){
    Edge minVal=peekMinVal();
    deleteVal(peekMinKey());
    return minVal;
}
//add value to priority queue with key index
//arguments - key index, edge
void IndexedPriorityQueue::insert(int keyIndex, Edge val){
    priorityMap[keyIndex] = currSize;
    inverseMap[currSize] = keyIndex;
    values[keyIndex] = val;
    swim(currSize++);
}
//remove edge value from priority queue at given key index
//arguments - key index
Edge IndexedPriorityQueue::deleteVal(int keyIndex){
    int index = priorityMap[keyIndex];
    swap(index, --currSize);
    sink(index);
    swim(index);
    Edge value = values[keyIndex];
    priorityMap[keyIndex] = -1;
    inverseMap[currSize] = -1;
    return value;
}
//swap edges if given edge is smaller than edge in queue
//arguments - key index, edge
void IndexedPriorityQueue::decrease(int keyIndex,Edge val){
    if (val<values[keyIndex]) {
        values[keyIndex] = val;
        swim(priorityMap[keyIndex]);
    }
}
//adjust heap stay sorted with new value going down
//arguments - position map index
void IndexedPriorityQueue::sink(int index){
    for (int x = minChild(index); x != -1; ) {
        swap(index, x);
        index = x;
        x = minChild(index);
    }
}
//adjust heap stay sorted with new value going up
//arguments - position map index
void IndexedPriorityQueue::swim(int index){
    while (values[inverseMap[index]]<values[inverseMap[parent[index]]]) {
        swap(index, parent[index]);
        index = parent[index];
    }
}
//return min child index
//arguments - position map index
int IndexedPriorityQueue::minChild(int i){
    int index = -1;
    int from = child[i];
    int to = min(currSize, from + degree);
    for (int x = from; x < to; x++){
        if (values[inverseMap[x]]<values[inverseMap[i]]){
            index = i = x;
        }
    }
    return index;
}
//swap index values
void IndexedPriorityQueue::swap(int i, int j){
    priorityMap[inverseMap[j]] = i;
    priorityMap[inverseMap[i]] = j;
    int tmp = inverseMap[i];
    inverseMap[i] = inverseMap[j];
    inverseMap[j] = tmp;
}