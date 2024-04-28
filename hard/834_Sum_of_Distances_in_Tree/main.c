#include <stdio.h>

void DFS (int *ret, int** graph, int node, int parent, int *count) {
 int top = graph[node][0];
 int child;

 for (int i = 1; i <= top; i++) {
  child = graph[node][i]; 
  if (child != parent) {
   DFS (ret, graph, child, node, count);
   count[node] += count[child];
   ret[node] += ret[child] + count[child];
  }
 }

}

void DFS2 (int *ret, int** graph, int size, int node, int parent, int *count) {
 int top = graph[node][0];
 int child;
 for (int i = 1; i <= top; i++) {
  child = graph[node][i];
  if (child != parent) {
   ret[child] = ret[node] - count[child] + (size - count[child]);
   DFS2 (ret, graph, size, child, node, count);
  }
 }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumOfDistancesInTree(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
 int *ret = (int*) calloc(n, sizeof(int));
 int *count = (int*) malloc(n * sizeof(int)); // count the nodes of subtree
 int **graph;
 int u, v;
 int *uTop, *vTop;
 int top;

 graph = (int**) malloc(n * sizeof(int*));
 for (int i = 0; i < n; i++) graph[i] = (int*) calloc(1, sizeof(int));
 for (int i = 0; i < n; i++) count[i] = 1;

 *returnSize = n;

 // realloc
 for (int i = 0; i < edgesSize; i++) {
  u = edges[i][0];
  v = edges[i][1];
  (*graph[u])++;
  (*graph[v])++;
 }

 for (int i = 0; i < n; i++) {
  top = graph[i][0] + 1;
  free(graph[i]);
  graph[i] = (int*) calloc(top, sizeof(int));
 }

 for (int i = 0; i < edgesSize; i++) {
  u = edges[i][0];
  v = edges[i][1];
  uTop = graph[u];
  vTop = graph[v];
  graph[u][++(*uTop)] = v;
  graph[v][++(*vTop)] = u;
 }


 // dfs
 DFS (ret, graph, 0, -1, count);
 DFS2 (ret, graph, n, 0, -1, count);

 // free memory
 for (int i = 0; i < n; i++) free(graph[i]);
 free(graph);
   
 return ret;
}

int main (void) {

 return 0;
}
