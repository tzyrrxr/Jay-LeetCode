#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Order is two ways.
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
 bool hashTable[10000] = {0};

 int *ret = (int*) malloc(2 * sizeof(int));

 // bubble sort
 for (int i = 0; i < numsSize; i++) {
  for (int j = 0; j < numsSize - i - 1; j++) {
   int tmp;
   if (nums[j] > nums[j+1]) {
    tmp = nums[j];
    nums[j] = nums[j+1];
    nums[j+1] = tmp;
   }
  }
 }
 for (int i = 0; i < numsSize; i++)  {
  if(hashTable[i]) ret[0] = nums[i];
  else hashTable[i] = 1;
 }

 ret[1] = 0;
 for(int i = nums[1]; i < nums[numsSize-1]; i++) {
  if (hashTable[i] == 0) {
   ret[1] = i;
   break;
  }
 }

 if (ret[1] == 0) {
  if (nums[0] == 1) ret[1] = nums[numsSize-1] + 1; 
  else ret[1] = nums[0] - 1;
 }

 *returnSize = 2;
 return ret;
}

int main (void) {

 return 0;
}
