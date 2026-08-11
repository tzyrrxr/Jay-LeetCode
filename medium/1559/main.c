int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool **visited;

bool DFS (int x, int y, int prePos_x, int prePos_y, int val, char **g, int m, int n) {
  visited[x][y] = true;

  for (int i = 0; i < 4; i++) {
    // new position
    int new_x = x + dx[i];
    int new_y = y + dy[i];

    if (new_x < 0 || new_y < 0 || new_x >= m || new_y >= n // skip if out of range
      || g[new_x][new_y] != val
      || (prePos_x == new_x && prePos_y == new_y) // backward?
      ) {
      continue;
    } 
    if (visited[new_x][new_y] || !DFS(new_x, new_y, x, y, val, g, m, n)) {
      return false; // find cycle
    }
  }
  return true; // no cycle
}
void freeVisited(int m) {
  for (int i = 0; i < m; i++) {
    free(visited[i]);
  }
  free(visited);
}
bool containsCycle(char** grid, int gridSize, int* gridColSize) {
  int m = gridSize;
  int n = *gridColSize;
  int prePos[] = {-1,-1};

  visited = (bool**) malloc(m*sizeof(bool*));
  for (int i = 0; i < m; i++) {
    visited[i] = (bool*) calloc(n, sizeof(bool));
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (visited[i][j]) {
       continue;
      } else if (!DFS(i, j, prePos[0], prePos[1], grid[i][j], grid, m, n)){
        freeVisited(m);
        return true; // find cycle
      }
    }
  }

  freeVisited(m);
  return false;
}
