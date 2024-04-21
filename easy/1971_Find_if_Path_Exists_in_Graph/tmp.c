#include <stdbool.h>
#include <stdlib.h>

bool DFS(int **adj, int curr, int destination, bool *visited) {
    if (curr == destination) return true;  // If current node is the destination
    visited[curr] = true;                 // Mark the current node as visited

    for (int i = 1; i <= adj[curr][0]; i++) {  // Iterate over all neighbors
        int next = adj[curr][i];
        if (!visited[next]) {              // If the neighbor has not been visited
            if (DFS(adj, next, destination, visited)) return true;  // Recur for DFS
        }
    }

    return false;  // Return false if no path found
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    if (n == 1) return true;  // Single node always has a path to itself

    int **adj = (int**) calloc(n, sizeof(int*));  // Allocate memory for adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = (int*) calloc(n + 1, sizeof(int));  // Allocate memory for each list, large enough for all nodes
    }

    // Build the adjacency list
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][0]++;
        adj[u][adj[u][0]] = v;

        adj[v][0]++;
        adj[v][adj[v][0]] = u;
    }

    bool *visited = (bool*) calloc(n, sizeof(bool));  // Allocate memory for visited array
    bool result = DFS(adj, source, destination, visited);  // Call DFS

    // Free memory
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);

    return result;
}

