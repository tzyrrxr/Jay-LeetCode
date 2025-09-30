#include <stdio.h>
#include <stdlib.h>

int triangularSum(int* nums, int numsSize) {
  int *ret = nums;

  while (--numsSize) {
    for (int i = 0; i < numsSize; i++) {
      nums[i] = (nums[i] + nums[i+1]) % 10;
    }
  }

    
  return (int)*ret;
}
