#include <stdio.h>

int countPartitions(int* nums, int numsSize) {
  int sum = 0;
  int lSum = 0;
  int cnt = 0;

  for (int i = 0; i < numsSize; i++) {
    sum += nums[i];
  }

  for (int i =0; i < numsSize-1; i++) {
    lSum += nums[i];
    if ((sum - lSum*2)%2 == 0) {
      cnt++;
    }
  }

  return cnt;
}
