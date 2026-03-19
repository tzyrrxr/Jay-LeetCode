int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
  int cnt = 0;
  int m = gridSize;
  int n = *gridColSize;
  int *sx = (int*) malloc(m*n*sizeof(int));
  int *sy = (int*) malloc(m*n*sizeof(int));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      sx[i*n+j] = (grid[i][j] == 'X');
      sy[i*n+j] = (grid[i][j] == 'Y');
      if (i > 0) {
        sx[i*n+j] += sx[(i-1)*n+j];
        sy[i*n+j] += sy[(i-1)*n+j];
      }
      if (j > 0) {
        sx[i*n+j] += sx[i*n+j-1];
        sy[i*n+j] += sy[i*n+j-1];
      }
      if (i>0 && j>0) {
        sx[i*n+j] -= sx[(i-1)*n+j-1];
        sy[i*n+j] -= sy[(i-1)*n+j-1];
      }
      if (sx[i*n+j] == sy[i*n+j] && sx[i*n+j] > 0) {
        cnt++;
      }
    }
  }
  free(sx);
  free(sy);
    
  return cnt;
}
