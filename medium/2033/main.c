int CMP(const void *a, const void *b) {
  return *(int*) a - *(int*) b;
}
int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
  int m = gridSize;
  int n = *gridColSize;
  int **g = grid;
  int ret = INT_MAX;
  int len = m*n;
  int *arr = (int*)malloc(len*sizeof(int));
  int *prefix = (int*)calloc(len,sizeof(int));
  int *suffix = (int*)calloc(len,sizeof(int));

  int reminder = g[0][0] % x;

  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++) {
      // existed result?
      if (g[i][j] % x != reminder) return -1;
      arr[i*n+j] = g[i][j];
    }
  }
  qsort(arr, m*n, sizeof(int), CMP);

  for (int i = 1; i < len; i++) {
    prefix[i] = prefix[i-1] + arr[i-1];
  }
  for (int i = len-2; i >= 0; i--) {
    suffix[i] = suffix[i+1] + arr[i+1];
  }

  for (int i = 0; i < len; i++) {
    int LOperation = (arr[i]*i - prefix[i]) / x;
    int ROperation = (suffix[i]- arr[i]*(len-1-i)) / x;
    ret = fmin(ret, LOperation + ROperation);
  }

  free(arr);
  free(suffix);
  free(prefix);
    
  return ret;
}
