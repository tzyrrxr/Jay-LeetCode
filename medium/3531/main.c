#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int countCoveredBuildings(int n, int** buildings, int buildingsSize, int* buildingsColSize) {
  int cnt = 0;
  // brute force
  for (int i = 0; i < buildingsSize; i++) {
    int x = buildings[i][0];
    int y = buildings[i][1];
    bool top = 0, down = 0, right = 0, left = 0;
    for (int j = 0; j < buildingsSize; j++) {
      if (j == i) continue;
      // right
      if (buildings[j][0] > x && buildings[j][1] == y) right = 1;
      // left
      else if (buildings[j][0] < x && buildings[j][1] == y) left = 1;
      else if (buildings[j][1] < y && buildings[j][0] == x) top = 1;
      else if (buildings[j][1] > y && buildings[j][0] == x) down = 1;
      if (top && down && right && left) {
        cnt++;
        break;
      }
    }
  }

  return cnt;
    
}
