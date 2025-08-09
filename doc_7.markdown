# Dijkstra’s Algorithm Documentation

## Data Structure Definition
- **Graph**: Struct with 2D array `adjMatrix` (size 100x100) and integer `vertices`.

## Functions Implemented
- `initGraph(Graph *g, int vertices)`: Initializes adjacency matrix with 0s (diagonal) and INF (elsewhere).
- `addEdge(Graph *g, int u, int v, int weight)`: Adds a directed edge with weight.
- `dijkstra(Graph *g, int src)`: Computes shortest paths from source using Dijkstra’s algorithm.

## Main Method Organization
- Creates a graph with 5 vertices.
- Adds weighted edges: (0,1,4), (0,2,8), (1,2,2), (1,3,5), (2,3,5), (2,4,9), (3,4,4).
- Runs Dijkstra’s algorithm from vertex 0 and prints distances.

## Sample Output
```
Shortest distances from vertex 0:
To 0: 0
To 1: 4
To 2: 6
To 3: 9
To 4: 13
```