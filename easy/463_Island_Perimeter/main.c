#include <stdio.h>

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
 int ret = 0;
 int row = gridSize;
 int col = *gridColSize;

 for (int r = 0; r < row; r++) {
  for (int c = 0; c < col; c++) {
   if (1 == grid[r][c]) {
    ret += 4;

    // down
    if (r + 1 < row && grid[r+1][c] == 1) ret--;
    // right
    if (c + 1 < col && grid[r][c+1] == 1) ret--;
    // up
    if (r - 1 > 0   && grid[r-1][c] == 1) ret--;
    // left
    if (c - 1 > 0   && grid[r][c-1] == 1) ret--;

   }
  }
 }

 return ret;
}

int main (int argc, char *argv[]) {
 return 0;
}
