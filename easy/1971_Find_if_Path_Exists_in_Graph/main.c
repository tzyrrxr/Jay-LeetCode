#include <stdio.h>

bool DFS (int **p, int s, int d, bool *visited) {
 if (s == d) return true;

 bool ret = false;

 visited[s] = 1;

 while (p[s][0] != 0) {
  int cur = p[s][0];
  if (!visited[p[s][cur]]) {
   ret = DFS(p, p[s][cur], d, visited);
   if (ret) break;
  }
  if (p[s][0]) p[s][0]--;
 }

 return ret;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
 if (n == 1) return true;
 int m = 0;
 if (n / edgesSize > 10000) m = 100;
 else if (n >= 20000) m = 300;
 else if (n > 10000) m = 1000;
 else m = 3000;

 int **path;
 int ret = false;
 int u, v;
 int *visited;
 path = (int**) calloc(n, sizeof(int*));
 for (int i = 0; i < n; i++) path[i] = (int*) calloc( m, sizeof(int));


 // record edges
 for (int i = 0; i < edgesSize; i++) {
  u = edges[i][0];
  v = edges[i][1];

  path[u][0]++;
  path[u][path[u][0]] = v;

  path[v][0]++;
  path[v][path[v][0]] = u;
 }

 visited = (int*) calloc(n, sizeof(bool));
 ret = DFS (path, source, destination, visited);
    
 return ret;
}

int main (void) {

 return 0;
}
