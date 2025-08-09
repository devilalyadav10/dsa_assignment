#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 99999

typedef struct {
    int adjMatrix[MAX][MAX];
    int vertices;
} Graph;

void initGraph(Graph *g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            g->adjMatrix[i][j] = (i == j) ? 0 : INF;
}

void addEdge(Graph *g, int u, int v, int weight) {
    g->adjMatrix[u][v] = weight;
}

void dijkstra(Graph *g, int src) {
    int dist[MAX], visited[MAX] = {0};
    for (int i = 0; i < g->vertices; i++) dist[i] = INF;
    dist[src] = 0;
    for (int i = 0; i < g->vertices - 1; i++) {
        int u = -1;
        for (int j = 0; j < g->vertices; j++)
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) u = j;
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < g->vertices; v++)
            if (!visited[v] && g->adjMatrix[u][v] != INF)
                if (dist[u] + g->adjMatrix[u][v] < dist[v])
                    dist[v] = dist[u] + g->adjMatrix[u][v];
    }
    printf("Shortest distances from vertex %d:\n", src);
    for (int i = 0; i < g->vertices; i++)
        printf("To %d: %d\n", i, dist[i] == INF ? -1 : dist[i]);
}

int main() {
    Graph g;
    initGraph(&g, 5);
    addEdge(&g, 0, 1, 4);
    addEdge(&g, 0, 2, 8);
    addEdge(&g, 1, 2, 2);
    addEdge(&g, 1, 3, 5);
    addEdge(&g, 2, 3, 5);
    addEdge(&g, 2, 4, 9);
    addEdge(&g, 3, 4, 4);
    dijkstra(&g, 0);
    return 0;
}