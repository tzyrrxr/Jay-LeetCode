#define SWAP(a,b) do { \
  __typeof(a) __tmp = (a); \
  (a) = (b); \
  (b) = __tmp; \
} while(0);

int minSwaps(int** grid, int gridSize, int* gridColSize) {
  int n = gridSize;
  int steps = 0;
  int list[200] = {0};

  for (int i = 0; i < n; i++) {
    int accept = 0;
    for (int j = n-1; j >= 0; j--) {
      if (grid[i][j] == 0) {
        accept++;
      } else {
        list[i] = n - accept;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    int row_target = i + 1;
    int row_accept = i;
    if (row_target < list[i]) {
      row_accept = -1;
      for (int j = i; j < n; j++) {
        if (row_target >= list[j]) {
          row_accept = j;
          break;
        }
      }
    }

    if (row_accept == -1) return -1;

    for (int j = row_accept; j > i; j--) {
      SWAP(list[j], list[j-1]);
      steps++;
    }
  }

  return steps;

}
