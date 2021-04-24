#include <iostream>
#include <fstream>

using namespace std;
//C:\\Users\\watso\\Documents\\Visual_Studio_Code\\Networkx_Graph_Generation\\test_graph.dat
int main(int argc, char** argv){
    string filePath="../test_graph.dat";
    ifstream file;
    cout<<"Reading "<<filePath<<"..."<<endl;
    //open file
    file.open(filePath);
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file "<<filePath<<"." << endl;
        return 1;
    }

    //graph



    //create graph
    while(!file.eof()){

    }

    return 0;
}

//how can i be faster
//preallocate vector sizes