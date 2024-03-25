#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
 int max = 0;
 int tmpSum = 0;
 for (int i = 0; i < k; i++) tmpSum += nums[i];
 max = tmpSum;

 if (k < numsSize) {
  for (int i = k; i < numsSize; i++) {
   tmpSum -= nums[i-k];
   tmpSum += nums[i];
   if (max < tmpSum) max = tmpSum;
  }
 }
    
 return (double) max / k;
}

int main (void) {

 return 0;
}
