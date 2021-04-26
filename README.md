# CS 3353 Programming Project 4
This repository was created and maintained by Kirk Watson.

Student ID: 47876885

Email: klwatson@smu.edu

## Functionality
This program implements 2 different algorithms that find the Minimum Spanning Tree for a given graph.
The program reads an undirected and weighted graph from a text file.
After reading the graph, the program finds a MST using Eager Prim's algorithm and Kruskal's algorithm with a Union Find data structure.
Once the MSTs are found, the number of edges in the MST, cost of the MST, and the running time for each algorithm is displayed to the terminal.

## How to Use
To use this program, the user will need to provide a display flag and a formatted text file.

### There are 5 command-line arguments:
* Display Flag
  * -b : Brief output, only displays MST number of edges and cost
  * -f : Full output, display brief output as well as algorithm running times  
* Absolute file path to the graph .dat/.txt file
  * Formatting
    * Must contain a connected, undirected, and weighted graph
    * Takes edges separated by each line with edge values separated by a space
    * Edge values are integers and are written in this order
      * *To*   *From*  *Weight*
    * Value for the first vertex must be 0 
  * Example:  
    0 1 9  
    0 2 0  
    0 3 5  
    0 5 7  
    1 3 -2  
    1 4 3  
    1 6 4  
    2 5 6  
    3 5 2  
    3 6 3  
    4 6 6  
    5 6 1  
## Analysis