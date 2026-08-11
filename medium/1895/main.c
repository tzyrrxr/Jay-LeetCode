#include <math.h>

int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
  int **rowSum = (int**) malloc(gridSize * sizeof(int*));
  int **colSum = (int**) malloc(*gridColSize * sizeof(int*));
  int side = fmin(gridSize, *gridColSize);

  // init rowSum
  for (int i = 0; i < gridSize; i++) {
    rowSum[i] = (int*) malloc((gridColSize[0] + 1) * sizeof(int));
    rowSum[i][0] = 0;
    for (int j = 0; j < gridColSize[0]; j++) {
      rowSum[i][j+1] = rowSum[i][j] + grid[i][j];
    }
  }

  // init colSum
  for (int j = 0; j < gridColSize[0]; j++) {
    colSum[j] = (int*) malloc((gridSize + 1) * sizeof(int));
    colSum[j][0] = 0;
    for (int i = 0; i < gridSize; i++) {
      colSum[j][i+1] = colSum[j][i] + grid[i][j];
    }
  }

  for (int s = side; s >= 2; s--) {
    for (int i = 0; i <= gridSize - s; i++) {
      for (int j = 0; j <= *gridColSize - s; j++) {
        int sideSum = rowSum[i][j + s] - rowSum[i][j];
        // check every row and column
        int k;
        for (k = 0; k < s; k++) {
          if (rowSum[i+k][j+s] - rowSum[i + k][j] != sideSum) {
            break;
          }
          if (colSum[j+k][i+s] - colSum[j+k][i] != sideSum) {
            break;
          }
        }

        if (k < s) {
          continue;
        }
        // check diagonals
        int diag1 = 0, diag2 = 0;
        for (k = 0; k < s; k++) {
          diag1 += grid[i+k][j+k]; // top-left to bottom-right
          diag2 += grid[i+k][j+s-1-k]; // top-right to bottom-left
        }
        if (diag1 == sideSum && diag2 == sideSum) {
          // free memory
          for (int i = 0; i < gridSize; i++) {
            free(rowSum[i]);
          }
          for (int i = 0; i < *gridColSize; i++) {
            free(colSum[i]);
          }

          free(rowSum);
          free(colSum);
          return s;
        }
      }
    }
  }


  return 1;
    
}
