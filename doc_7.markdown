Given a weighted graph, implement Dijkstra’s algorithm to find the shortest path from a
source node to all other nodes.

## Data Structure Definition
The program represents a weighted directed graph using an adjacency matrix within a `Graph` structure. The structure includes a 2D array `adjMatrix` of size `MAX` (100) by `MAX`, where `adjMatrix[i][j]` stores the weight of the edge from vertex `i` to vertex `j`, or `INF` (99999) if no edge exists. For each vertex `i`, `adjMatrix[i][i]` is set to 0, representing no cost to itself. An integer `vertices` tracks the number of vertices, enabling efficient storage and access for weighted connections in the graph.

## Function Descriptions
The program implements functions to construct the graph and compute shortest paths. The `initGraph` function initializes the graph by setting the number of vertices and filling the adjacency matrix with 0 for diagonal entries (self-loops) and `INF` for all other entries, indicating no edges initially. The `addEdge` function adds a directed edge from vertex `u` to vertex `v` with a specified weight by setting `adjMatrix[u][v]` to the weight, updating the graph’s connectivity. The `dijkstra` function implements Dijkstra’s algorithm to find the shortest paths from a source vertex to all others: it initializes an array `dist` with `INF` for all vertices except the source (set to 0), uses a `visited` array to track processed vertices, and iteratively selects the unvisited vertex with the smallest distance, updates distances to its neighbors if a shorter path is found, and prints the shortest distance to each vertex (or -1 if unreachable).

## Main Function Overview
The `main` function demonstrates Dijkstra’s algorithm on a sample graph. It creates a graph with 5 vertices, initializes it, and adds directed edges with weights: 0->1 (4), 0->2 (8), 1->2 (2), 1->3 (5), 2->3 (5), 2->4 (9), and 3->4 (4). It then calls `dijkstra` with source vertex 0 to compute and print the shortest distances from vertex 0 to all other vertices, returning 0 to indicate successful execution.

## Sample Output
When the program runs with the specified graph, it produces the following output:
```
Shortest distances from vertex 0:
To 0: 0
To 1: 4
To 2: 6
To 3: 9
To 4: 13
```
This output shows the shortest distances from vertex 0 to each vertex, calculated as: 0 to itself (0), 0->1 (4), 0->1->2 (4+2=6), 0->1->3 (4+5=9), and 0->1->3->4 (4+5+4=13), confirming the algorithm’s correct computation of shortest paths.
