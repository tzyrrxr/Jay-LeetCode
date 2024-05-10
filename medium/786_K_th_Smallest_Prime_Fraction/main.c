#include <stdio.h>

int CMP(const void *a, const void *b) {
 return *(int*) a - *(int*) b;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize) {
 int *ret = (int *) malloc(2 * sizeof(int));

 *returnSize = 2;

 if (k==1) {
  ret[0] = arr[0];
  ret[1] = arr[arrSize-1];
  return ret;
 }

 int len = arrSize * arrSize;
 float *s = (float*) malloc(len * sizeof(float));
 float *pt;
 int count = 0;

 for (int i = 0; i < arrSize; i++) {
  for (int j = i+1; j < arrSize; j++) {
   s[count++] = (float) arr[i] / (float) arr[j];
  }
 }

 qsort (s, count, sizeof(int), CMP);

 for (int i = 0; i < arrSize; i++) {
  for (int j = i+1; j < arrSize; j++) {

   if (s[k-1] == (float) arr[i] / (float) arr[j]) {
    ret[0] = arr[i];
    ret[1] = arr[j];
    return ret;
   }

  }
 }

 return ret;
    
}

int main (void) {

 return 0;
}
