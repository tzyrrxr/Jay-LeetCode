#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  int* queue;
  int head;
  int tail;
  int count;
  int size;
} NodeQueue;

int Max(int a, int b);
NodeQueue* CreateNode (int size);
int enQueue (NodeQueue *q, int num);
int deQueue (NodeQueue *q);
bool IsEmptyQueue (NodeQueue *q);
bool IsFullQueue (NodeQueue *q);
void BFS (int startNode, int *dist, int *edges, int edgesSize);
int closestMeetingNode(int* edges, int edgesSize, int node1, int node2);

int Max (int a, int b) {
  return a > b ? a : b;
}

NodeQueue* CreateNode (int size) {
  NodeQueue *ret = (NodeQueue*) malloc(sizeof(NodeQueue));
  ret->queue = (int*) malloc(size * sizeof(int));
  ret->head = ret->tail = 0;
  ret->count = 0;
  ret->size = size;
  return ret;

}

int enQueue (NodeQueue *q, int num) {
  if (IsFullQueue(q)) return -1;
  q->queue[q->head] = num;
  q->head = (q->head + 1) % q->size;
  q->count++;
  return 0;
}

int deQueue (NodeQueue *q) {
  if (IsEmptyQueue(q)) return -1;
  int ret = q->queue[q->tail];
  q->tail = (q->tail + 1) % q->size;
  q->count--;
  return ret;
}

bool IsEmptyQueue (NodeQueue *q) {
 return q->count == 0;
}

bool IsFullQueue (NodeQueue *q) {
 return q->count == q->size;
}

void BFS (int startNode, int *dist, int *edges, int edgesSize) {
  bool *visit = (bool*) calloc(edgesSize, sizeof(bool));
  NodeQueue *q = CreateNode(edgesSize);
  int node;
  int neighbor;

  enQueue(q, startNode);

  dist[startNode] = 0;

  while (!IsEmptyQueue(q)) {
    node = deQueue (q);

    if (node < 0 || node >= edgesSize || visit[node]) {
      continue;
    }

    visit[node] = true;

    neighbor = edges[node];
    if (neighbor != -1 && !visit[neighbor]) {
      dist[neighbor] = dist[node] + 1;
      enQueue(q, neighbor);
    }

  }

  free(visit);
  free(q->queue);
  free(q);

}

int closestMeetingNode(int* edges, int edgesSize, int node1, int node2) {
  int *dist1, *dist2;
  int retNode = -1;
  int currNode = 0;
  int tmpDepth = INT_MAX;

  dist1 = (int*) malloc(edgesSize * sizeof(int));
  dist2 = (int*) malloc(edgesSize * sizeof(int));
  memset (dist1, 0xff, edgesSize * sizeof(int));
  memset (dist2, 0xff, edgesSize * sizeof(int));

  // Create the shortest path
  BFS (node1, dist1, edges, edgesSize);
  BFS (node2, dist2, edges, edgesSize);

  for (currNode = 0; currNode < edgesSize; currNode++) {
    if (dist1[currNode] == -1 || dist2[currNode] == -1) continue;

    if (tmpDepth > Max(dist1[currNode], dist2[currNode])) {
      retNode = currNode;
      tmpDepth = Max(dist1[currNode], dist2[currNode]);
    }
  }

  free(dist1);
  free(dist2);
    
  return retNode;

}


//int main () {
// int edges[] = {2,2,3,-1};
// int ret;
//
// ret = closestMeetingNode(edges, sizeof(edges)/sizeof(edges[0]), 0, 1);
//
// return ret;
//}
