#include <stdio.h>

int islanddPerimeter(int** grid, int gridSize, int* gridColSize) {
 unsigned int ret = 0;
 unsigned int top[*gridColSize] = down[*gridColSize] = {0};
 unsigned int left[gridSize] = right[gridSize] = {0};

 for (int i = 0; i < gridSize; i++) {
  int row = 0;
  for (int j = 0; j < *gridColSize; j++) {
   if (grid[gridSize][*gridColSize]) {
    top[j] = down[j] = 1;
    row = 1;
   }
  }
  left[i] = right[i] = row;
 }

 // combine
 for (int i = 0; i < gridSize; i++) 


 return ret;
}

int main (int argc, char *argv[]) {
 return 0;
}
