int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
 int ret = 0;

 for (int r = 0; r < gridSize; r++) {
  for (int c = 0; c < *gridColSize; c++) {
   if (grid[r][c]) {
    ret += 4;

    if (r-1 >= 0 && grid[r-1][c]) ret--;
    if (r+1 < gridSize && grid[r+1][c]) ret--;

    if (c-1 >= 0 && grid[r][c-1]) ret--;
    if (c+1 < *gridColSize && grid[r][c+1]) ret--;

   }
  }
 }

 return ret;
}
