#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Order is two ways.
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
 int min, max;
 // bubble sort
 for (int i = 0; i < numsSize; i++) {
  for (int j = 0; j < numsSize -i -1; j++) {
   int tmp;
   if (nums[j] > nums[j+1]) {
    tmp = nums[j];
    nums[j] = nums[j+1];
    nums[j+1] = tmp;
   }
  }
 }
 min = nums[0];
 max = nums[numsSize-1];

 int *ret = (int *) malloc(2 * sizeof(int));

 if (numsSize == 2 && nums[0] == nums[1]) {
  if (nums[0] == 1) {
   ret[0] = nums[0];
   ret[1] = nums[1] + 1;
  } else {
   ret[0] = nums[0];
   ret[1] = nums[1] - 1;
  }
 } else {
  // above 3 items

  int tmpIndex;
  for (int i = 1; i < numsSize; i++) {
   if (nums[i-1] == nums[i]) {
    ret[0] = nums[i];
    tmpIndex = i;
    break;
   }
  }

  for (int i = 1; i < numsSize; i++) {
   if (i == tmpIndex) continue;
   if (i == numsSize-1) {
    if (nums[0] == 2) ret[1] = 1;
    else ret[1] = nums[i] + 1;
    break;
   }
  }

 }

 *returnSize = 2;
 return ret;
}

int main (void) {

 return 0;
}
