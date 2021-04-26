//Kirk Watson - 47876885 - CS3353
#ifndef S21_PA04_KWATSON_UNIONFIND_H
#define S21_PA04_KWATSON_UNIONFIND_H

using namespace std;

//This class holds the Union Find data structure.
class UnionFind {
private:
    int* unionSize;         //tracks size of each union
    int* connections;       //tracks connections for each node

public:
    UnionFind();
    UnionFind(int);

    int find(int);
    bool connected(int, int);
    int size(int);
    void unify(int, int);
};


#endif //S21_PA04_KWATSON_UNIONFIND_H
