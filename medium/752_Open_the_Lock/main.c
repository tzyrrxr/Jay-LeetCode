#include <stdio.h>
#include <stdlib.h>

int openLock(char** deadends, int deadendsSize, char* target) {
 int dead[10000] = {0};
 int visited[10000] = {0};
 int tmp;
 int steps = 0;

 char stack[10000][5];
 int top = -1;

 for (int i = 0; i < deadendsSize; i++) {
  tmp = atoi(deadends[i]);
  if (!tmp) return -1;
  else dead[tmp] = 1;
 }

 stack[++top] = "0000\0";

 while (top != -1) {
  steps++;
  int size = top + 1;
  for (int i = 0; i < size; i++) {
   char* curr = stack[top];
   top--;
   for (int j = 0; j < 4; j++) {
    for (int z = -1; z <=1; z+=2) {
     curr[j] = (curr[j] - '0' + z + 10) % 10 + '0';
     if (strcmp(curr) == strcmp(target)) return steps;
     if (dead[atoi(curr)] || visited[atoi(curr)]) continue;
     stack[++top] = curr;
     visited[atoi(curr)] = 1;
    }
   }
  }
 }

 return -1;
}

int main (void) {

 return 0;
}
