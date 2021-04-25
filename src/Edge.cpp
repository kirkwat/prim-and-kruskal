//
// Created by watso on 4/25/2021.
//

#include "Edge.h"

Edge::Edge() {

}
Edge::Edge(int t, int f,  int c){
    to=t;
    from=f;
    cost=c;
}
//greater than operator with string
bool Edge::operator> (const Edge& copy)const{
    return cost>copy.cost;
}
//less than operator with string
bool Edge::operator< (const Edge& copy)const{
    return cost<copy.cost;
}
int Edge::getCost(){
    return cost;
}
int Edge::getTo(){
    return to;
}
int Edge::getFrom(){
    return from;
}