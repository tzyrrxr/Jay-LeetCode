#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CMP (void const *a, void const *b) {
  return *(int*) a - *(int*) b;
}

int heightChecker(int* heights, int heightsSize) {
  int ret = 0;
  int *order = (int *) malloc(heightsSize * sizeof(int));

  memcpy (order, heights, heightsSize * sizeof(int));
  qsort (order, heightsSize, sizeof(int), CMP);

  for (int i = 0; i < heightsSize; i++) {
    if (order[i] != heights[i]) ret++;
  }

  free(order);

  return ret;
}

int main (void) {
  int test[] = {5,1,2,3,4};
  heightChecker (test, 5);
 
 return 0;
}
