#include <stdio.h>

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void DFS (char** grid, int h, int w, int r, int c) {
 int dc, dr;

 for (int i = 0; i < 4; i++) {
  dc = c + dir[i][0];
  dr = r + dir[i][1];
  if ( dc >= 0 && dc < w &&
       dr >= 0 && dr < h &&
       '1' == grid [dr][dc] 
    ) {
   grid [dr][dc] = '0';
   DFS (grid, h, w, dr, dc);
  }
 }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
 int ret = 0;
 int col = *gridColSize;
 int row = gridSize;
    
 for (int r = 0; r < row; r++) {
  for (int c = 0; c < col; c++) {
   if (grid[r][c] == '1') {
    grid[r][c] = '0';
    ret++;
    DFS(grid, row, col, r, c);
   }
  }
 }

 return ret;
}

int main (void) {

 return 0;
}
