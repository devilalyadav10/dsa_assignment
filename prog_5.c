#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int adjMatrix[MAX][MAX];
    int vertices;
} Graph;

void initGraph(Graph *g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            g->adjMatrix[i][j] = 0;
}

void addEdge(Graph *g, int u, int v) {
    g->adjMatrix[u][v] = g->adjMatrix[v][u] = 1;
}

void BFS(Graph *g, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < g->vertices; v++)
            if (g->adjMatrix[u][v] && !visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
            }
    }
    printf("\n");
}

void DFSUtil(Graph *g, int v, int *visited) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < g->vertices; i++)
        if (g->adjMatrix[v][i] && !visited[i])
            DFSUtil(g, i, visited);
}

void DFS(Graph *g, int start) {
    int visited[MAX] = {0};
    printf("DFS: ");
    DFSUtil(g, start, visited);
    printf("\n");
}

int main() {
    Graph g;
    initGraph(&g, 5);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);
    BFS(&g, 0);
    DFS(&g, 0);
    return 0;
}