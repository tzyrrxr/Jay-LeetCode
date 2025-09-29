#include <stdio.h>
#include <stdlib.h>
#include <limit.h>

int minScoreTriangulation(int* values, int valuesSize) {
  // DP table to store the mini sum of value.
  int DP[valuesSize][valuesSize];
  int gap = 2;
  int s = 0, m = 0, e = 0;

  memset(DP, 0, sizeof(DP));

  for (gap = 2; gap < valuesSize; gap++) {
    for (s = 0; s + gap < valuesSize; s++) {
      e = s + gap;
      DP[s][e] = INT_MAX;

      for (m = s+1; m < e; m++) {
        if (DP[s][e] > DP[s][m] + DP[m][e] + values[s] * values[m] * values[e]) {
          DP[s][e] = DP[s][m] + DP[m][e] + values[s] * values[m] * values[e];
        }
      }
    }
  }
    
  return DP[0][valuesSize-1];
}

int main () {

  return 0;
}
