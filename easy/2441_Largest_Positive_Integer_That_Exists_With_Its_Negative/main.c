#include <stdio.h>

int findMaxK(int* nums, int numsSize) {
 int hash[1001] = {0};
 int i = 0;
 int ret = -1;

 while (i < numsSize) {
  if (nums[i] > 0) {
   hash[nums[i]] = 1;
  }
  i++;
 }

 i = 0;
 while (i < numsSize) {
  if (nums[i] < 0 && hash[~nums[i]+0x1] == 1 && ret < ~nums[i]+0x1) {
   ret = ~nums[i]+0x1;
  }
  i++;
 }

 return ret;
}

int main (void) {

 return 0;
}
