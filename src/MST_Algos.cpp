//
// Created by watso on 4/24/2021.
//

#include "MST_Algos.h"
//default constructor
MST_Algos::MST_Algos(){}
//read file to fill graph
void MST_Algos::readGraph(const char* filePath){
    ifstream file;
    //open file
    file.open(filePath);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file "<<filePath<<"." << endl;
        return;
    }
    //get number of lines
    int numLines=0;
    string line;
    while(getline(file, line)){
        numLines++;
    }
    //create array based on size
    int values[3*numLines];
    //go to beginning of file
    file.clear();
    file.seekg(0);
    //get values
    int num;
    values[0]=num;
    //max vertex used to find graph dimension
    int max=num;
    //read values and find max vertex
    for(int x=1;x<(3*numLines);x++){
        file>>num;
        values[x]=num;
        //skip edge values
        if(((x+1)%3)!=0){
            //check for max
            if(num>max){
                max=num;
            }
        }
    }
    //close file
    file.close();
    //initialize graph with range
    graph=Graph(max);
    //fill graph
    for(int x=0;x<numLines;x++){
        int index=3*numLines;
        graph.AddEdge(index,index+1,index+2);
    }
    //TODO change maybe for min constraint
    nodes=max+1;
}
//find mst with prims algo
void MST_Algos::prim(){
    bool solved;
    bool mstExists;
    bool visited[nodes];

    int minCostSum;
}







































