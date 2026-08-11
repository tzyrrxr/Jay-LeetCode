#define MOD 12345

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** constructProductMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int n = gridSize;
    int m = *gridColSize;
    
    int **res = (int **) malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        res[i] = (int*) malloc(m*sizeof(int));
    }
    
    long long suffix = 1;
    for (int i = n-1; i >= 0; i--) {
      for (int j = m-1; j >= 0; j--) {
          res[i][j] = suffix % MOD;
          suffix = (grid[i][j] * suffix) % MOD;
      }
    }

    long long prefix = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          suffix = res[i][j];
          res[i][j] = (suffix * prefix) % MOD;
          prefix = (grid[i][j] * prefix) % MOD;
      }
    }
    
    *returnSize = n;
    *returnColumnSizes = (int*) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
    }
    return res;
}