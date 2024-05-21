#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
 int **ret;
 int subNum = pow(2, numsSize);
 *returnSize = subNum;
 *returnColumnSizes = (int*) malloc(subNum * sizeof(int));

 ret = (int **) malloc(subNum * sizeof(int*));

 for (int i = 0; i < subNum; i++) {
  int *subset = (int*) malloc(numsSize * sizeof(int));
  int index = 0;
  for (int j = 0; j < numsSize; j++) {
   if ((i >> j) & 1) subset[index++] = nums[j];
  }
  subset = (int*) realloc(subset, index * sizeof(int));
  ret[i] = subset;
  (*returnColumnSizes)[i] = index;
 }
    
 return ret;

}

int main (void) {
 
 return 0;
}
