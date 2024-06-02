#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* longestCommonSubsequence(int** arrays, int arraysSize, int* arraysColSize, int* returnSize) {
  int rows = arraysSize;
  int *ht = (int*) calloc(101, sizeof(int)); 
  int *ret = (int*) malloc(101 * sizeof(int));


  *returnSize = 0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < arraysColSize[r]; c++) {
      if(++ht[arrays[r][c]] == rows) ret[(*returnSize)++] = arrays[r][c];
    }

  }

  ret = (int*) realloc(ret, (*returnSize) * sizeof(int));
  free (ht);

  return ret;
    
}

int main (void) {
 
 return 0;
}
