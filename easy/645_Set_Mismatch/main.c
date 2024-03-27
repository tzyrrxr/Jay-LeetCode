#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Order is two ways.
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
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
  int order = 0;
  int left, right;
  for (int i = 1; i < numsSize && order == 0; i++) {
   if (i-2 >= 0) left = nums[i-2];
   else left = nums[i-1];
   if (i+1 < numsSize) right = nums[i+1];
   else right = nums[i];

   if (left - right > 0) {
    // todo
    // determine order
   }

   order = nums[i] - nums[i-1];
  }
  for (int i = 1; i < numsSize; i++) {
   if (nums[i-1] == nums[i]) {
    ret[0] = nums[i];
    ret[1] = nums[i] + order;
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
