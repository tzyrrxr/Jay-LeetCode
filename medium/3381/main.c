#include <stdio.h>
#include <stdlib.h>

long long maxSubarraySum(int* nums, int numsSize, int k) {
  long long max = (long long)INT_MIN;
  long long sum = (long long)INT_MIN;
  for (int z = 1; z*k <= numsSize; z++) {
    // i contains first index of subarray
    for (int i = 0; i < numsSize - k*z + 1; i++) {
      sum = 0;
      for (int j = 0; j < k*z; j++) {
        sum += nums[i +j];
      }
      if (sum > max) max = sum;
    } 
  }

  return max;
}
