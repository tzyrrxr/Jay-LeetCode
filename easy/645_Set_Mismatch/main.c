#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Order is two ways.
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
 bool hashTable[11000] = {0};

 int *ret = (int*) malloc(2 * sizeof(int));
 int min, max;
 min = INT_MAX;
 max = INT_MIN;

 for (int i = 0; i < numsSize; i++)  {
  if (min > nums[i]) min = nums[i];
  if (max < nums[i]) max = nums[i];
  if(hashTable[nums[i]]) ret[0] = nums[i]; // find the duplicated number
  else hashTable[nums[i]] = 1;
 }

 ret[1] = 0;
 for(int i = min; i <= max; i++) {
  if (hashTable[i] == 0) {
   ret[1] = i;
   break;
  }
 }
 
 if (!ret[1] && numsSize == 2) {
  if (ret[0] == 1) ret[1] = 2;
  else ret[1] = ret[0] - 1;
 }

 if (!ret[1]) {
  if (min > 1) ret[1] = min - 1;
  else ret[1] = max + 1;
 }

 *returnSize = 2;
 return ret;
}



int main (void) {

 return 0;
}
