# Undirected Graph Traversal Documentation

## Data Structure Definition
- **Graph**: Struct with 2D array `adjMatrix` (size 100x100) and integer `vertices`.

## Functions Implemented
- `initGraph(Graph *g, int vertices)`: Initializes adjacency matrix with zeros.
- `addEdge(Graph *g, int u, int v)`: Adds an undirected edge between vertices u and v.
- `BFS(Graph *g, int start)`: Performs Breadth-First Search from the start vertex.
- `DFSUtil(Graph *g, int v, int *visited)`: Recursive helper for DFS.
- `DFS(Graph *g, int start)`: Performs Depth-First Search.

## Main Method Organization
- Creates a graph with 5 vertices.
- Adds edges: (0,1), (0,2), (1,3), (2,4).
- Performs BFS and DFS starting from vertex 0.

## Sample Output
```
BFS: 0 1 2 3 4
DFS: 0 1 3 2 4
```