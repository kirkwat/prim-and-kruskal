//
// Created by watso on 4/25/2021.
//

#ifndef S21_PA04_KWATSON_EDGE_H
#define S21_PA04_KWATSON_EDGE_H

using namespace std;

class Edge{
private:
    int to, from, cost;
public:
    Edge();
    Edge(int, int,  int);
    bool operator> (const Edge&)const;
    bool operator< (const Edge&)const;
    int getCost();
    int getTo();
    int getFrom();
    //TODO fix compare edges
};


#endif //S21_PA04_KWATSON_EDGE_H
