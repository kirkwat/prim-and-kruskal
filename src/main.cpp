//Kirk Watson - 47876885 - CS3353
#include "MST_Algos.h"

using namespace std;
//C:\\Users\\watso\\Documents\\Visual_Studio_Code\\Networkx_Graph_Generation\\test_graph.dat
int main(int argc, char** argv){
    //create launcher
    MST_Algos mst_finder=MST_Algos();
    //read file
    //string file="../test_graph.dat";
    //mst_finder.readGraph(file.c_str());
    //test graph
    mst_finder.testGraph();
    //prims algo
    mst_finder.prim();
    mst_finder.kruskal();








    return 0;
}
//to do
    //kruskals
    //union find
    //fix file reader
    //essay
    //prepare for turn in and competition


//how can i be faster
//reading file
    //getline+ss vs >>
    //counting lines to get array size before reading
    //adj matrix for prims on dense

//to add
    //absolute path
    //error handling

//constraints
    //lowest vertex must be 0