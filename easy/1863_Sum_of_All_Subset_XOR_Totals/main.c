#include <stdio.h>

int subsetXORSum(int* nums, int numsSize) {
 int ret = 0;

 for (int i = 0; i < numsSize; i++) ret |= nums[i];
    
 return ret << (numsSize-1);
}

int main (void) {
 
 return 0;
}
