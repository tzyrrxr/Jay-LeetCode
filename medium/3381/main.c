#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// presum
// remainder
long long maxSubarraySum(int* nums, int numsSize, int k) {
  long long max = LLONG_MIN;
  long long minPre = LLONG_MAX;
  long long *presum = (long long *) malloc ((numsSize+1) * sizeof (long long));
  //int sublen = 0;

  presum[0] = 0;
  for (int i = 0; i < numsSize; i++) {
    presum[i+1] = presum[i] + nums[i];
  }

  // remainder
  for (int r =0; r < k; r++) { 
    // reset minPre for each remainder
    minPre = LLONG_MAX;
    for (int i = r; i <= numsSize; i+=k) {
      if (minPre != LLONG_MAX) {
        if (max < presum[i] - minPre) {
          max = presum[i] - minPre; // presum[i]->more; minPre->less ==> max
        }

      }
      if (presum[i] < minPre) {
        minPre = presum[i];
      }
    }
  }

  free(presum);

  return max;
}
