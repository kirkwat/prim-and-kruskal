//Kirk Watson - 47876885 - CS3353
#include "Edge.h"
//default constructor
Edge::Edge() {
    to=0;
    from=0;
    weight=0;
}
//overloaded constructor with edge values
//arguments - to, from, weight
Edge::Edge(int t, int f,  int w){
    to=t;
    from=f;
    weight=w;
}
//greater than operator with cost
bool Edge::operator> (const Edge& copy)const{
    return weight>copy.weight;
}
//less than operator with cost
bool Edge::operator< (const Edge& copy)const{
    return weight<copy.weight;
}
//return cost value
int Edge::getWeight(){
    return weight;
}
//return to value
int Edge::getTo(){
    return to;
}
//return from value
int Edge::getFrom(){
    return from;
}