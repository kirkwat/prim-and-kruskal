//
// Created by watso on 4/25/2021.
//

#ifndef S21_PA04_KWATSON_UNIONFIND_H
#define S21_PA04_KWATSON_UNIONFIND_H

using namespace std;

class UnionFind {
private:
    int* sz;
    int* id;

public:
    UnionFind();
    UnionFind(int);

    int find(int);
    bool connected(int, int);
    int size(int);
    void unify(int, int);
};


#endif //S21_PA04_KWATSON_UNIONFIND_H
