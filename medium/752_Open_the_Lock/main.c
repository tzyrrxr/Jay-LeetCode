#include <stdio.h>
#include <stdlib.h>

int openLock(char** deadends, int deadendsSize, char* target) {
 int dead[10000] = {0};
 int tmp;
 int steps = 0;

 char stack[10000][4];
 int top = -1;

 for (int i = 0; i < deadendsSize; i++) {
  tmp = atoi(deadends[i]);
  if (!tmp) return -1;
  else dead[tmp] = 1;
 }

 stack[++top] = "0000";



 return -1;
}

int main (void) {

 return 0;
}
