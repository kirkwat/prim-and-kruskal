//Kirk Watson - 47876885 - CS3353
#include "MST_Algos.h"
//default constructor
MST_Algos::MST_Algos(){
    int nodes=0;
}
//read file to fill graph, returns true if file was successfully read
//arguments - graph data file path
bool MST_Algos::readGraph(const char* filePath){
    ifstream file;
    //open file
    file.open(filePath);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file "<<filePath<<"." << endl;
        return false;
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
    //fill graph and priority queue
    for(int x=0;x<numLines;x++){
        int index=3*x;
        graph.AddEdge(values[index],values[index+1],values[index+2]);
        pq.push(Edge(values[index],values[index+1],values[index+2]));
    }
    nodes=max+1;
    return true;
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
    //display mst cost
    cout<<"MST cost with Prim's algo:\t\t"<<mstCost<<endl;
}
//find mst with kruskals algo
void MST_Algos::kruskal() {
    int mstCost=0;
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
        //end loop if mst with all nodes has been found
        if (uf.size(0) == nodes){
            break;
        }
    }
    //verify algo mst tree is full
    if(uf.size(0) == nodes){
        cout<<"MST cost with Kruskal's algo:\t"<<mstCost<<endl;
    }
}