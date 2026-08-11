#define SWAP(a,b) do { \
  __typeof__(a) __tmp = (a); \
  (a) = (b); \
  (b) = __tmp; \
} while(0)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize) {
  int n = arrSize;
  int *res = (int*) malloc(n * sizeof(int));
  int *bitNum = (int*) malloc(n * sizeof(int));

  memcpy(res, arr, n * sizeof(int));

  for (int i = 0; i < n; i++) {
    int tmp = res[i];
    int cnt = 0;
    while (tmp) {
      if (tmp&1) cnt++;
      tmp >>= 1;
    }
    bitNum[i] = cnt;
  }

  // bubble sort
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (bitNum[j] > bitNum[j+1]) {
        SWAP(bitNum[j], bitNum[j+1]);
        SWAP(res[j], res[j+1]);
      } else if (bitNum[j] == bitNum[j+1] && res[j] > res[j+1]) {
        SWAP(res[j], res[j+1]);
      }
    }
  }
    
  *returnSize = n;
  free(bitNum);

  return res;
}
