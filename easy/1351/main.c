//        n
//     <-----
//   ^ B ...
//   | .    .
// m | .    .
//   | .    .
//   | ...  S
//
// 1. check [0][n], if negative, then all below are negative, then check [0][n-1] until positve found.
// 2. if [0][n] is positive, check[1][n], until negative found.
//
int countNegatives(int** grid, int gridSize, int* gridColSize) {
  int cnt = 0;
  int bit = sizeof(int) * 8 - 1;;
  int m = gridSize;
  int n = *gridColSize;
  int i = 0, j = n-1;

  while (i < m && j >= 0) {
    if (grid[i][j] >> bit) {
      cnt += m - i;
      j--;
    } else {
      i++;
    }
  }
    
  return cnt;
}
