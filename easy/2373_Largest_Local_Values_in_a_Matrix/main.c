#include <stdio.h>

int findMax (int** grid, int x, int y, int gridSize) {
 int ret = INT_MIN;
 for (int i = x; i < x+3 && i < gridSize; i++) {
  for (int j = y; j < y+3 && j < gridSize; j++) {
   if (ret < grid[i][j]) ret = grid[i][j];
  }
 }

 return ret;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
 int n = gridSize;
 int **ret = (int**) malloc((n-2) * sizeof(int*));
 *returnColumnSizes = (int*) malloc((n-2) * sizeof(int));
 for (int i = 0; i < n-2; i++) {
  ret[i] = (int*) malloc((n - 2) * sizeof(int));
  (*returnColumnSizes)[i] = n-2;
 }

 for (int i = 0; i < n-2; i++) {
  for (int j = 0; j < n-2; j++) {
   ret[i][j] = findMax(grid, i, j, n);
  }
 }


 *returnSize = n - 2;
 return ret;
    
}

int main (void) {

 return 0;
}
