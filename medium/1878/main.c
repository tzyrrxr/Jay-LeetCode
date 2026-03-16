void updateTop3 (int* res, int val) {
  if (res[0] < val) {
    res[2] = res[1];
    res[1] = res[0];
    res[0] = val;
  } else if (res[1] < val && res[0] > val) {
    res[2] = res[1];
    res[1] = val;
  } else if (res[2] < val && res[1] > val) {
    res[2] = val;
  }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getBiggestThree(int** grid, int gridSize, int* gridColSize, int* returnSize) {
  *returnSize = 0;
  int *res = (int*) malloc(3 * sizeof(int));
  for (int i = 0; i < 3; i++) {
    res[i] = -1;
  }
  int r = gridSize;
  int c = *gridColSize;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      // L = 0
      updateTop3 (res, grid[i][j]);

      int L = 1; 
      // grid[i][j] is the top point.
      while (i + L + L < r && j-L >= 0 && j+L < c) {
        int sum = 0;
        // count 4 L
        for (int k = 0; k < L; k++) sum += grid[i+k][j+k]; // top to right
        for (int k = 0; k < L; k++) sum += grid[i+L+k][j+L-k];; // right to down
        for (int k = 0; k < L; k++) sum += grid[i+L+L-k][j-k]; // down to left
        for (int k = 0; k < L; k++) sum += grid[i + L - k][j - L + k]; // left to top
        updateTop3 (res, sum);
        L++;
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    if (res[i] != -1) (*returnSize)++;
  }

  if ((*returnSize) != 3) {
    res = (int*)realloc(res, sizeof(int) * (*returnSize));
  }

  return res;
}
