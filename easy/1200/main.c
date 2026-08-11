int CMP (const void *a, const void *b) {
  return *(int*) a - *(int*) b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
  int **res = NULL;
  int diff = INT_MAX;
  int cnt = 0;
  qsort(arr, arrSize, sizeof(int), CMP);

  for (int i = 1; i < arrSize; i++) {
    if (arr[i]-arr[i-1]< diff) diff = arr[i]-arr[i-1];
  }

  for (int i = 1; i < arrSize; i++) {
    if (arr[i]-arr[i-1]== diff) {
      cnt++;
    }
  }
  *returnSize = cnt;

  res = (int**) malloc(cnt * sizeof(int*));
  *returnColumnSizes = (int*) malloc(cnt * sizeof(int));

  for(int i = 1, ri = 0; i < arrSize; i++) {
    if (arr[i]-arr[i-1]== diff) {
      res[ri] = (int*) malloc(2*sizeof(int));
      (*returnColumnSizes)[ri] = 2;
      res[ri][0] = arr[i-1];
      res[ri][1] = arr[i];
      ri++;
    }
  }


  return res;
}
