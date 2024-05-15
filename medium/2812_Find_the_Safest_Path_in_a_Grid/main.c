#include <stdio.h>

struct Node {
 int x;
 int y;
};

int dir[4][2] = {
 {0, 1}, {0, -1},
 {1, 0}, {-1, 0}
};

bool isValidSafeness (int **grid, int n, int sVal) {
 if (grid[0][0] < sVal || grid[n-1][n-1] <sVal) return false;
 struct Node tq[401] = {0};
 bool v[401][401] = {0};
 int head = 0;
 int rear = -1;
 tq[++rear] = {0, 0};
 v[0][0] = 1;

 while (rear >= head) {
  struct Node curr = tq[head++];
  // the corner of right and down
  if (curr.x == n - 1 && curr.y == n - 1) return true;

  // checking neighboring cells
  for (int i = 0; i < 4; i++) {
   int dx = curr.x + d[i][0];
   int dy = curr.y + d[i][1];
   if ((dx >= 0 || dy >= 0 || dx < n || dy < n) && v[dy][dx] == 0 && grid[dy][dx] >= sVal) {
    v[dy][dx] = 1;
    tq[++rear] = {dx, dy};
   }
  }
 }


 // no valid path found
 return false;

}

int maximumSafenessFactor(int** grid, int gridSize, int* gridColSize){
 // matrix = n x n
 int n = gridSize;
 int head = 0;
 int rear = -1;
 struct Node q[401] = {0};

 for (int i = 0; i < n; i++) {
  for (int j = 0; j < n; j++) {
   if (grid[i][j]) {
    q[++rear] = {j, i};
    grid[i][j] = 0;
   } else {
    grid[i][j] = -1;
   }
  }
 }

 while (rear >= head) {
  int size = rear - head + 1;
  while (size-- > 0) {
   struct Node curr = q[head++];
   for (int i = 0; i < 4; i++) {
    int dx = curr.x + dir[i][0];
    int dy = curr.y + dir[i][1];
    int val = grid[curr.y][curr.x];
    if (dx >= 0 && dy >= 0 && dx < n && dy < n && grid[dy][dx] == -1) {
     grid[dy][dx] = val + 1;
     q[++rear] = {dx, dy};
    }
   }
   
  }
 }

 // Binary Search
 int start = 0;
 int end = 0;
 int ret = -1;
 int mid;
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < n; j++) {
   if (end < grid[i][j]) end = grid[i][j];
  }
 }

 while (end >= start) {
  mid = start + (end - start) / 2;
  if (isValidSafeness(grid, n, mid)) {
   ret = mid;
   start = mid + 1;
  } else {
   mid = end - 1;
  }
 }

 return ret;

}

int main (void) {

 return 0;
}
