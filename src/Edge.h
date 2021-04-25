//Kirk Watson - 47876885 - CS3353
#ifndef S21_PA04_KWATSON_EDGE_H
#define S21_PA04_KWATSON_EDGE_H

using namespace std;

//This class contains the characteristics of a directed edge in a graph.
class Edge{
private:

    int to;         //start vertex of edge
    int from;       //destination vertex of edge
    int weight;     //cost of edge
public:
    Edge();
    Edge(int, int,  int);

    bool operator> (const Edge&)const;
    bool operator< (const Edge&)const;

    int getWeight();
    int getTo();
    int getFrom();
};


#endif //S21_PA04_KWATSON_EDGE_H
