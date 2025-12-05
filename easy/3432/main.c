#include <stdio.h>

// The x mean sum of left.
// The y mean sum of right.
// Target: Count (x - y == even)
// sum = x + y
// if sum of array is even: x and y are both even or both odd. ==> x-y == even
// if sum of array is odd: (x is even and y is odd) or (x is odd and y is even). ==> x-y == odd
int countPartitions(int* nums, int numsSize) {
  int sum = 0;
  {
    int i = -1;
    while (++i < numsSize) sum += nums[i];
  }

  return (sum & 1) ? 0 : numsSize - 1;
}
