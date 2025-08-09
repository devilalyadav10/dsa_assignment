How can we implement the undirected graph using adjacency matrix? Write a function that
implement the BFS and DFS technique to traverse through the graph. Demonstrate the
use of your program with example graph.

## Data Structure Definition

The program represents an undirected graph using an adjacency matrix\, encapsulated in a Graph structure\. This structure includes a 2D array adjMatrix of size MAX \(100\) by MAX\, where each entry adjMatrix\[i\]\[j\] is 1 if an edge exists between vertices i and j\, or 0 otherwise\. The structure also contains an integer vertices to store the number of vertices in the graph\, allowing efficient representation and manipulation of undirected connections in a fixed\-size matrix\.

## Function Descriptions

The program implements functions to initialize\, modify\, and traverse the graph\. The initGraph function sets up the graph by assigning the number of vertices and initializing the adjacency matrix to all zeros\, indicating no edges initially\. The addEdge function adds an undirected edge between vertices u and v by setting adjMatrix\[u\]\[v\] and adjMatrix\[v\]\[u\] to 1\, ensuring symmetry for the undirected graph\. The BFS function performs a breadth\-first search starting from a given vertex: it uses a queue to track vertices to visit\, a visited array to avoid revisiting\, and prints vertices in order of exploration\, checking adjacent vertices and enqueuing unvisited ones\. The DFSUtil function is a recursive helper for depth\-first search\, marking a vertex as visited\, printing it\, and recursively exploring unvisited adjacent vertices\. The DFS function initiates depth\-first search by initializing a visited array and calling DFSUtil to print the traversal starting from a specified vertex\.

## Main Function Overview

The main function demonstrates the graph traversal algorithms. It creates a graph with 5 vertices, initializes it, and adds undirected edges to form connections: 0-1, 0-2, 1-3, and 2-4. It then calls BFS starting from vertex 0 to print the breadth-first traversal, followed by DFS starting from vertex 0 to print the depth-first traversal. The function returns 0 to indicate successful execution, showcasing both traversal techniques on the example graph.

## Sample Output

When the program runs with the specified graph, it produces the following output:
<br>
```
BFS: 0 1 2 3 4
DFS: 0 1 3 2 4
```

This output shows the BFS traversal visiting vertices level by level (starting from 0, then 1 and 2, then 3 and 4) and the DFS traversal exploring as far as possible along each branch (0 to 1 to 3, backtracking, then 2 to 4), reflecting the structure of the graph with vertices 0, 1, 2, 3, and 4 and their respective connections.
