int countNegatives(int** grid, int gridSize, int* gridColSize) {
  int cnt = 0;
  int bit = sizeof(int) * 8 - 1;;

  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < *gridColSize; j++) {
      if (grid[i][j] >> bit) cnt++;
    }
  }
    
  return cnt;
}
