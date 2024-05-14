#include <stdio.h>

int dir[4][2] = {
 {0, 1}, {0, -1},
 {1, 0}, {-1, 0}
}; 

int DFS (int** grid, int col, int row, int x, int y) {
 if (x < 0 || y < 0 || x == col || y == row || grid[y][x] == 0) return 0;
 int val = grid[y][x];
 int max = 0;
 int tmp;
 grid[y][x] = 0;
 for (int d = 0; d < 4; d++) {
  if (dir[d][0]+x < 0 || dir[d][1]+y < 0 || dir[d][0] >= col || dir[d][1] >= row) continue;
  tmp = DFS(grid, col, row, dir[d][0]+x, dir[d][1]+y);
  if (max < tmp) max = tmp;
 }

 grid[y][x] = val;
 return val + max;
  
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize) {
 int ret = INT_MIN;
 int row = gridSize;
 int col = *gridColSize;
 int tmp;

 for (int i = 0; i < row; i++) {
  for (int j = 0; j < col; j++) {
   tmp = DFS (grid, col, row, j, i);
   if (ret < tmp) ret = tmp;
  }
 }
    
 return ret;

}

int main (void) {

 return 0;
}
