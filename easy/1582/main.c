int numSpecial(int** mat, int matSize, int* matColSize) {
  int cnt = 0;
  int m = *matColSize;
  int n = matSize;
  int *rowCnt = calloc(n, sizeof(int));
  int *colCnt = calloc(m, sizeof(int));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 1) {
        rowCnt[i]++;
        colCnt[j]++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (rowCnt[i] == 1) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 1 && colCnt[j] == 1) {
          cnt++;
        }
      }
    }
  }

  free(rowCnt);
  free(colCnt);
    
  return cnt;
}
