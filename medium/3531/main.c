#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int countCoveredBuildings(int n, int** buildings, int buildingsSize, int* buildingsColSize) {
  int cnt = 0;
  // hash
  // ex: x[0] = (yMin, yMax)
  // ex: y[0] = (xMin, xMax)
  int **xHash = (int**)malloc((n+1)*sizeof(int*));
  int **yHash = (int**)malloc((n+1)*sizeof(int*));
  for (int i = 0; i <= n; i++) {
    xHash[i] = (int*)malloc(2*sizeof(int));
    xHash[i][0] = INT_MAX;
    xHash[i][1] = INT_MIN;
    yHash[i] = (int*)malloc(2*sizeof(int));
    yHash[i][0] = INT_MAX;
    yHash[i][1] = INT_MIN;
  }

  // fulfill hash table
  for (int i = 0; i < buildingsSize; i++) {
    int x = buildings[i][0];
    int y = buildings[i][1];

    // x hash table
    // check MIN
    if (xHash[x][0] > y) xHash[x][0] = y;
    // check MAX
    if (xHash[x][1] < y) xHash[x][1] = y;

    // y hash table
    // check MIN
    if (yHash[y][0] > x) yHash[y][0] = x;
    // check MAX
    if (yHash[y][1] < x) yHash[y][1] = x;
  }

  // count covered buildings
  for (int i = 0; i < buildingsSize; i++) {
    int x = buildings[i][0];
    int y = buildings[i][1];

    if (xHash[x][0] == INT_MAX ||
        xHash[x][1] == INT_MIN ||
        yHash[y][0] == INT_MAX ||
        yHash[y][1] == INT_MIN) {
          continue;
        }

    if (x < yHash[y][1] && 
        x > yHash[y][0] && 
        y < xHash[x][1] && 
        y > xHash[x][0]) {
      cnt++;
    }
  }
  for (int i = 0; i <= n; i++) {
    free (xHash[i]);
    free (yHash[i]);
  }
  free(xHash);
  free(yHash);

  return cnt;
    
}
