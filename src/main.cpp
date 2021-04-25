#include <iostream>
#include <fstream>
#include "MST_Algos.h"

using namespace std;
//C:\\Users\\watso\\Documents\\Visual_Studio_Code\\Networkx_Graph_Generation\\test_graph.dat
int main(int argc, char** argv){
    //create launcher
    MST_Algos mst_finder=MST_Algos();
    //read file
    string file="../test_graph.dat";
    mst_finder.readGraph(file.c_str());


    return 0;
}

//how can i be faster
//reading file
    //getline+ss vs >>
    //counting lines to get array size before reading