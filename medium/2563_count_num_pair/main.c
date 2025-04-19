#include <stdio.h>

// key point, don't think the order, just pair.

int CMP (void const *a, void const *b) {
  return *(int*)a - *(int*)b;
}

// fit lower bound element to let sum > lower value
// fit lower bound element to let sum < higher value
// low, high == index
// element == value
int fit_lower_bound (int* nums, int low, int high, int element) {
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (nums[mid] >= element) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return low;

}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    long long count = 0;
    qsort (nums, numsSize, sizeof(int), CMP);

    for (int i = 0; i < numsSize; i++) {
      int low  = fit_lower_bound (nums, i+1, numsSize-1, lower - nums[i]);
      int high  = fit_lower_bound (nums, i+1, numsSize-1, upper - nums[i] + 1); // plus one to fit equal upper
      // range of index data is fit lower <= nums[i] + nums[low:high] <= upper
      count += (long long) (high - low); 
    }

    return count;

}

int main (void) {
 
 return 0;
}
