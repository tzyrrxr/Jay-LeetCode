void rotate(int** matrix, int matrixSize, int* matrixColSize) {
  int len = matrixSize;
  // reverse the diagonal and then reverse left and right
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      int tmp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = tmp;
    }
  }

  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len/2; j++) {
      int tmp = matrix[i][j];
      matrix[i][j] = matrix[i][len-1-j];
      matrix[i][len-1-j] = tmp;
    }
  }
    
}
