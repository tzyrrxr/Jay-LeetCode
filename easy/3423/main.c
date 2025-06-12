#include <stdio.h>
#include <limits.h>

int maxAdjacentDistance(int* nums, int numsSize) {
  int max = INT_MIN;
  int i;
  int tmp;

  for (i = 0; i < numsSize-1; i++) {
    tmp = (nums[i] - nums[i+1]) >= 0 ? (nums[i] - nums[i+1]) : ~(nums[i] - nums[i+1]) + 1;
    if (max < tmp) max = tmp;
  }

  tmp = (nums[i] - nums[0]) >= 0 ? (nums[i] - nums[0]) : ~(nums[i] - nums[0]) + 1;
  if (max < tmp) max = tmp;

  return max;
    
}

int main () {
  int test[] = {-5, 10, -5};
  int ret;

  ret = maxAdjacentDistance (test, sizeof(test)/ sizeof(int));
  printf("result: %d\n", ret);

  return 0;
}
