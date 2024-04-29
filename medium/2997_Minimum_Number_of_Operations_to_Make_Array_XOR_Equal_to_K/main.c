#include <stdio.h>

int minOperations(int* nums, int numsSize, int k) {
 int initVal = 0;
 int ret = 0;

 for (int i =0; i < numsSize; i++) initVal ^= nums[i]; 

 while (initVal || k) {
  if (initVal%2 != k%2) ret++;
  initVal>>=1; 
  k>>=1;
 }

 return ret;
}

int main (void) {

 return 0;
}
