#include <stdio.h>

int main() {
    int graph[20][20];
    int n, edges;
    int i, j, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize matrix with 0
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for(i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    printf("\nAdjacency Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }

    return 0;
}