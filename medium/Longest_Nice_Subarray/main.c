#include <stdio.h>

int longestNiceSubarray(int* nums, int numsSize) {
  int checker = 0;
  int counter = 1;
  int ret = counter;

  for (int i = 0; i < numsSize; i++) {
    checker = nums[i];

    ret = counter > ret ? counter : ret;
    counter = 1;

    for (int j = i+1; j < numsSize; j++) {
      if (checker & nums[j] != 0) break;
      counter++;
      checker |= nums[j];
    }
  }

  return ret;
}

int main(VOID) {

  return 0;

}
