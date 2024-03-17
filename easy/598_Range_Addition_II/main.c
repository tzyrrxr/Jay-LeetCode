#include <stdio.h>

int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
 if (!opsSize) return m * n;
 int rowMin = INT_MAX;
 int colMin = INT_MAX;

 *opsColSize = 2;
 for (int i = 0; i < opsSize; i++) {
  if (rowMin > ops[i][0]) rowMin = ops[i][0];
  if (colMin > ops[i][1]) colMin = ops[i][1];
 }

 return rowMin * colMin;
}

int main (void) {

 return 0;
}
