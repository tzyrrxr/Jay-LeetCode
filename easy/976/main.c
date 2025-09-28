#include<stdio.h>

int CMP (const void *a, const void *b) {
  return (*(int*)b - *(int*)a);
}

int largestPerimeter(int* nums, int numsSize) {
  int max = 0;

  qsort (nums, numsSize, sizeof(int), CMP);

  for (int i = 0; i < numsSize - 2; i++) {
    if (nums[i] < nums[i+1] + nums[i+2]) {
      max = nums[i] + nums[i+1] + nums[i+2];
      break;
    }
  }

  return max;
    
}
