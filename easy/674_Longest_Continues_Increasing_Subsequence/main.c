#include <stdio.h>

int findLengthOfLCIS(int* nums, int numsSize) {
 if (numsSize == 1) return 1;

 int max = 1;
 int l;

 for (int i = 1, l = 0; i < numsSize; i++) {
  if (nums[i] <= nums[i-1]) {
   l = i;
  } else if (i - l + 1 > max){
   max = i - l + 1;
  }
 }

 return max;
}

int main (void) {

 return 0;
}
