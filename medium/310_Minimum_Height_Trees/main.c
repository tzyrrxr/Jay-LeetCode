#include <stdio.h>

int Front(int* q, int top) {
 int tmp = q[0];
 for (int i = 0; i < top; i++) q[i] = q[i+1];
 return tmp;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
 int* ret = (int*) malloc(n * sizeof(int));
 int rear = -1;

 if (n == 1) {
  *returnSize = 1;
  ret[++rear] = 0;
  return ret;
 }
 int *deg = (int*) calloc(n, sizeof(int));

 int **path = (int**) malloc(n * sizeof(int*));
 *path = (int*) calloc(n, sizeof(int));

 int *queue = (int*) calloc(n, sizeof(int));

 // record
 for(int i = 0; i < edgesSize; i++) {
  int v = edges[i][0];
  int u = edges[i][1];
  int vTop = ++path[v][0];
  int uTop = ++path[u][0];


  deg[v]++;
  deg[u]++;
  path[v][vTop] = u;
  path[u][uTop] = v;

 }
 
 // record leaf
 for (int i = 0; i < n; i++) {
  if (deg[i] == 1) {
   queue[++rear] = i;
  }
 }

 while (rear >= 0) {
  
  int size = rear + 1;
  for (int i = 0; i < size; i++) {
   int tmp = Front(queue, rear);
   int top;
   int val;
   rear--;
   top = path[tmp][0];
   path[tmp][0]--;
   val = path[tmp][top];
   deg[val]--;
   if (deg[val] == 1) queue[++rear] = val;
  }

  *returnSize = rear+1;

 }
    
 return queue;
}

int main (void) {

 return 0;
}
