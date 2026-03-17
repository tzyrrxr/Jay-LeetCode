int CMP (const void *a, const void *b) {
  return *(int*) b - *(int*)a;
}
int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
  int rows = matrixSize;
  int cols = *matrixColSize;
  int maxArea = 0;

  for (int i = 1; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 1) {
        matrix[i][j] += matrix[i-1][j];
      }
    }
  }

  for (int i = 0; i < rows; i++) {
    int rowHeight[cols];
    for (int j = 0; j < cols; j++) {
      rowHeight[j] = matrix[i][j];
    }
    qsort (rowHeight, cols, sizeof(int), CMP);

    for (int j = 0; j < cols; j++) {
      if (rowHeight[j] == 0) break;
      int currArea = rowHeight[j] * (j+1);
      if (maxArea < currArea) {
        maxArea = currArea;
      }
    }
  }
    
  return maxArea;
}
