/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes) {
  for (int i = 0; i < k; i++) {
    int t = 0;
    int d = k-1;
    while (t < d) {
      int tmp = grid[x+t][y+i];
      grid[x+t][y+i] = grid[x+d][y+i];
      grid[x+d][y+i] = tmp;
      t++;
      d--;
    }
  }

  *returnSize = gridSize;
  *returnColumnSizes = (int*) malloc(gridSize*sizeof(int));
  for (int i = 0; i < gridSize; i++){
    (*returnColumnSizes)[i] = *gridColSize;
  }
   
  return grid;
}
