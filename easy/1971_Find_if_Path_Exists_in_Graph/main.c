#include <stdio.h>

bool DFS (int **p, int n, int s, int d) {
 if (p[s][d]) return true;
 bool ret = false;
 for (int i = 0; i < n; i++) {
  if (p[s][i]) {
   p[s][i] = 0;
   ret = DFS (p, n, i, d);
   if (ret) break;
  }
 }

 return ret;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
 if (n == 1) return true;

 int **path;
 int ret = false;
 path = (int**) calloc(n, sizeof(int*));
 for (int i = 0; i < n; i++) path[i] = (int*) calloc(n, sizeof(int));

 // record edges
 for (int i = 0; i < edgesSize; i++) {
   path[edges[i][0]][edges[i][1]] = 1;
   path[edges[i][1]][edges[i][0]] = 1;
 }

 ret = DFS (path, n, source, destination);
    
 return ret;
}

int main (void) {

 return 0;
}
