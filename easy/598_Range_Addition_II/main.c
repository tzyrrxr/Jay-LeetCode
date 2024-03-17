#include <stdio.h>

int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
 if (!opsSize) return m * n;

 int maxProbe = 0;
 int i;
 int totalCount = m * n;
 int *indexCount = (int *) calloc(totalCount, sizeof(int));

 *opsColSize = 2;
 for (int i = 0; i < opsSize; i++) {
  for (int j = 0; j < ops[i][0] * ops[i][1]; j++) {
   indexCount[j]++;
  }
 }

 maxProbe = indexCount[totalCount-1];
 for (i = 0; i < totalCount; i++) {
  if (maxProbe <= indexCount[i]) maxProbe = indexCount[i];
  else break;
 }

 return i;
}

int main (void) {

 return 0;
}
