#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
  int hash[10^8 + 1] = {0};
  int* heap = (int*) calloc(10^5, sizeof(int));
  int count = 1;

  for (int i = 0; i < numsSize; i++) hash[nums[i] + 10^4]++;

  for (int i = 0; i < numsSize; i++) {
    
  }

    
}

int main (void) {
 
 return 0;
}
