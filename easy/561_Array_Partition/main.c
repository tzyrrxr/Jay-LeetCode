#include <stdio.h>

#define SWAP(a, b) {a = a + b; b = a - b; a = a - b;}

int arrayPairSum(int* nums, int numsSize) {
  // bubble sort: increasing order
  int ret = 0;
  for (int i = 0; i < numsSize; i++) {

    for (int j = 0; j < numsSize-i-1; j++) {
      if (nums[j] > nums[j+1]) {
        SWAP(nums[j+1], nums[j])
      }

    }

    // sum of odd index of number
    if (i % 2 == 1) {
      ret += nums[numsSize-i-1];
    }

  }

  return ret;
}

int main (void) {

 return 0;
}
