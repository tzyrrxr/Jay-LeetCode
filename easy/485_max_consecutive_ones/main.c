#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
 int maxLen = -1;
 int tmpLen = 0;

 for (int i = 0; i < numsSize; i++) {
  if (nums[i]) {
   tmpLen++;
   if (tmpLen > maxLen) maxLen = tmpLen;
  } else {
   tmpLen = 0;
  }
 }

 return maxLen == -1 ? 0 : maxLen;
}
