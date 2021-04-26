//Kirk Watson - 47876885 - CS3353
#include "MST_Algos.h"
//default constructor
MST_Algos::MST_Algos(){
    int nodes=0;
}
//read file to fill graph
//arguments - graph data file path
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
    int num;        //TODO check this
    file>>num;
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
        //pq.push(index+1,Edge(index,index+1,index+2)); TODO fix
    }
    //TODO change maybe for min constraint
    nodes=max+1;
}
//find mst with prims algo
void MST_Algos::prim(){
    //array marking if vertex has been visited
    bool visited[nodes];
    for(int x=0;x<nodes;x++){
        visited[x]=false;
    }
    int connections=nodes-1;        //num of connections between vertices
    int mstCount=0;                 //num of current edges found
    int mstCost=0;                  //mst cost
    Edge mstEdges[connections];     //edges used in mst  //TODO delete
    //create ipq
    //degree of d-ary heap, for performance with dense and populated graphs
    int degree=ceil(log(nodes)/log(2));
    IndexedPriorityQueue ipq=IndexedPriorityQueue(max(2, degree),nodes);
    //start algo at index 0
    visited[0] = true;
    //get edges at index 0
    vector<Edge> edges = graph.at(0);
    //iterate through each edge
    for (Edge edge : edges) {
        //add edges to priority queue
        ipq.insert(edge.getTo(), edge);
    }
    //loop until priority queue is empty and current edges equals num of connections
    while (!ipq.isEmpty() && mstCount != connections) {
        //get destination vertex for min in priority queue
        int destVertex = ipq.peekMinKey();
        //get edge and add cost to mst cost
        Edge edge = ipq.pollMinVal();
        mstEdges[mstCount++] = edge;
        mstCost += edge.getWeight();
        //mark vertex as visited
        visited[destVertex] = true;
        //get edges connected to destination vertex
        edges = graph.at(destVertex);
        //iterate through edges
        for(Edge e : edges){
            //get edge destination
            destVertex = e.getTo();
            //check if destination vertex has already been visited
            if(visited[destVertex]){
                continue;
            }
            //check if destination vertex is in priority queue
            if(ipq.contains(destVertex)){
                //replace edge with lowest weight if possible
                ipq.decrease(destVertex, e);
            }
            else{
                //add new edge to priority queue
                ipq.insert(destVertex, e);
            }
        }
    }
    //show mst cost
    cout<<"Prim's MST cost: "<<mstCost<<endl;
    //show mst edges
    cout<<"Prim's MST edges: "<<endl;
    for (Edge edge : mstEdges) {
        printf("\t(%d, %d, %d)\n", edge.getFrom(), edge.getTo(), edge.getWeight());
    }
}
//find mst with kruskals algo
void MST_Algos::kruskal() {
    int mstCost=0;              //mst cost
    int mstCount=0;             //num of current edges found
    Edge mstEdges[nodes - 1];   //edges used in mst   //TODO delete
    //create union find object
    UnionFind uf = UnionFind(nodes);
    //loop until priority queue is empty
    while (!pq.empty()) {
        //get and pop min edge in priority queue
        Edge edge = pq.top();
        pq.pop();
        //skip edge if vertex is already connected to union and mst
        if (uf.connected(edge.getFrom(), edge.getTo())){
            continue;
        }
        //add edge to union and mst
        uf.unify(edge.getFrom(), edge.getTo());
        mstCost += edge.getWeight();
        mstEdges[mstCount++] = edge;
        //end loop if mst with all nodes has been found
        if (uf.size(0) == nodes){
            break;
        }
    }
    if(uf.size(0) == nodes){
        cout<<"kruskal's mst cost: "<<mstCost<<endl;
        cout<<"kruskal's MST edges: "<<endl;
        for (Edge edge : mstEdges) {
            printf("\t(%d, %d, %d)\n", edge.getFrom(), edge.getTo(), edge.getWeight());
        }
    }
}
//test graph
void MST_Algos::testGraph() {
    nodes=7;
    graph=Graph(nodes);
    //add edges
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

    pq.push(Edge(0,1,9));
    pq.push(Edge(0,2,0));
    pq.push(Edge(0,3,5));
    pq.push(Edge(0,5,7));
    pq.push(Edge(1,3,-2));
    pq.push(Edge(1,4,3));
    pq.push(Edge(1,6,4));
    pq.push(Edge(2,5,6));
    pq.push(Edge(3,5,2));
    pq.push(Edge(3,6,3));
    pq.push(Edge(4,6,6));
    pq.push(Edge(5,6,1));

    //print graph
    graph.print();
}