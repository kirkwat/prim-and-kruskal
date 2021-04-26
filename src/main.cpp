//Kirk Watson - 47876885 - CS3353
#include "MST_Algos.h"
#include <cstring>
#include "time.h"

using namespace std;
//C:\\Users\\watso\\Documents\\Visual_Studio_Code\\Networkx_Graph_Generation\\test_graph.dat //TODO delete
int main(int argc, char** argv){
    string file="../test_graph.dat";   //TODO delete
    //create mst solver
    MST_Algos mst_solver=MST_Algos();
    //read file
    if(mst_solver.readGraph(file.c_str())) {
        //brief output option with mst cost and edges
        if(strcmp(argv[1],"-b") == 0){
            //run prim's algo to find mst
            mst_solver.prim();
            //run kruskal's algo to find mst
            mst_solver.kruskal();
        }
        //full output option with mst info and time
        else if(strcmp(argv[1],"-f") == 0){
            //execute and time prims algo
            clock_t beginning = clock();
            mst_solver.prim();
            clock_t ending = clock();
            double runTime = (double) (ending - beginning) / CLOCKS_PER_SEC;
            cout<<"Running time with Prim's algo:\t\t\t\t\t"<<runTime<<"s"<<endl<<endl;
            //execute and time kruskals algo
            beginning = clock();
            mst_solver.kruskal();
            ending = clock();
            runTime = (double) (ending - beginning) / CLOCKS_PER_SEC;
            cout<<"Running time with Kruskal's algo:\t\t\t\t"<<runTime<<"s"<<endl;

        }
    }
    return 0;
}
//to do
    //fix absolute path right before turning in
    //readme basics
    //analysis
    //prepare for turn in and competition


//to add
    //absolute path
    //error handling