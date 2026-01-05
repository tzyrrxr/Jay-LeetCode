#include <stdbool.h>
#include <stdlib.h>

int twoComplement (int num) { return ~num + 1; }
// bitwise check should use unsigned to avoid sign extension bit complie warning.
bool isNegative (int num) { return num & (1U << (sizeof(int)*8 - 1)) ? 1 : 0; }

// number of array : negative, zero, positive
// any negative number of array is odd: subtract the smallest absolute value * 2 from total sum
// any negative pair zero can be converted to positive.
long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
  long long total = 0;
  int negCnt = 0;
  int zeroCnt = 0;
  int minAbs = INT_MAX;
  int **m = matrix;

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < *matrixColSize; j++) {
      int num = m[i][j];
      if (m[i][j] == 0) zeroCnt++;

      // negative
      if (isNegative(num)) {
        negCnt++;
        total += twoComplement(num);
        if (twoComplement(num) < minAbs) minAbs = twoComplement(num);
      } else { // positive
        total += num;
        if (num < minAbs) minAbs = num;
      }

    }
  }

  if (negCnt%2 == 1 && zeroCnt == 0) {
    total -= (minAbs*2);
  }

    
  return total;
}
