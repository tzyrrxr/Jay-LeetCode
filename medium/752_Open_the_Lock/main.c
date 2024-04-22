#include <stdio.h>
#include <stdlib.h>

int openLock(char** deadends, int deadendsSize, char* target) {
 if (atoi(target) == 0) return 0;
 bool dead[10000] = {0};
 bool visited[10000] = {0};
 int steps = 0;
 char curr[5];
 char next[5];

 char queue[20000][5] = {0};
 int front, rear;
 front = rear = -1;

 for (int i = 0; i < deadendsSize; i++) {
  int tmp = atoi(deadends[i]);
  if (tmp == 0) return -1;
  else dead[tmp] = 1;
 }

 strncpy(queue[++rear], "0000", 4);
 queue[rear][4] = '\0';
 front = 0;

 while (front <= rear) {
  steps++;
  int edge = rear + 1;
  for (int i = front; i < edge; i++) {
   strncpy(curr, queue[i], 4);
   curr[4] = '\0';
   front++;

   for (int j = 0; j < 4; j++) {
    for (int z = -1; z <= 1; z+=2) {
     strncpy(next, curr, 4);
     next[4] = '\0';

     next[j] = (next[j] - '0' + z + 10) % 10 + '0';
     if (!strcmp(next, target)) return steps;
     if (dead[atoi(next)] || visited[atoi(next)]) continue;
     strncpy(queue[++rear], next, 4);
     queue[rear][4] = '\0';
     visited[atoi(next)] = 1;

    }
   }
  }
 }

 return -1;
}

int main (void) {

 return 0;
}
