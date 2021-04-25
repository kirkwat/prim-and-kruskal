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
    IndexedPriorityQueue ipq;

    int minCostSum;
    int m=nodes-1;
    int edgeCount=0;
    bool visited[nodes];
    Edge mstEdges[m];

    int degree=ceil(log(nodes)/log(2));
    ipq=IndexedPriorityQueue(max(2, degree),nodes);












    visited[0] = true;

    // edges will never be null if the createEmptyGraph method was used to build the graph.
    vector<Edge> edges = graph.at(0);

    for (Edge edge : edges) {
        int destNodeIndex = edge.getTo();

        // Skip edges pointing to already visited nodes.
        if (visited[destNodeIndex]) continue;

        if (ipq.contains(destNodeIndex)) {
            // Try and improve the cheapest edge at destNodeIndex with the current edge in the IPQ.
            ipq.decrease(destNodeIndex, edge);
        } else {
            // Insert edge for the first time.
            ipq.insert(destNodeIndex, edge);
        }
    }














    while (!ipq.isEmpty() && edgeCount != m) {
        int destNodeIndex = ipq.peekMinKeyIndex(); // equivalently: edge.to
        Edge edge = ipq.pollMinValue();

        mstEdges[edgeCount++] = edge;
        minCostSum += edge.getCost();



        visited[destNodeIndex] = true;

        // edges will never be null if the createEmptyGraph method was used to build the graph.
        vector<Edge> edges = graph.at(destNodeIndex);

        for (Edge edge : edges) {
            int destNodeIndex = edge.getTo();

            // Skip edges pointing to already visited nodes.
            if (visited[destNodeIndex]) continue;

            if (ipq.contains(destNodeIndex)) {
                // Try and improve the cheapest edge at destNodeIndex with the current edge in the IPQ.
                ipq.decrease(destNodeIndex, edge);
            } else {
                // Insert edge for the first time.
                ipq.insert(destNodeIndex, edge);
            }
        }
    }

    // Verify MST spans entire graph.
    mstExists = (edgeCount == m);








    cout<<"MST cost: "<<minCostSum<<endl;





}
//TODO add getMSt, getMstCost, mstExists





void MST_Algos::testGraph() {
    graph=Graph(7);

    graph.AddEdge(0,1,9);
    graph.AddEdge(0,2,0);
    graph.AddEdge(0,3,5);
    graph.AddEdge(0,5,7);
    graph.AddEdge(1,3,-2);
    graph.AddEdge(1,4,3);
    graph.AddEdge(1,6,4);
    graph.AddEdge(2,5,6);
    graph.AddEdge(3,5,2);
    graph.AddEdge(3,6,3);
    graph.AddEdge(4,6,6);
    graph.AddEdge(5,6,1);

    graph.print();
}

























