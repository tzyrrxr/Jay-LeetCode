#include <stdio.h>

int maximumProduct(int* nums, int numsSize) {
 if (numsSize == 3) return nums[0]*nums[1]*nums[2];

 // bubble sort
 for (int i = 0; i < numsSize; i++) {
  for (int j = 0; j < numsSize-1-i; j++) {
   if (nums[j] < nums[j+1]) {
    int tmp = nums[j];
    nums[j] = nums[j+1];
    nums[j+1] = tmp;
   }
  }
 }

 return nums[0] * nums[1] * nums[2] > nums[numsSize-1] * nums[numsSize-2] * nums[0] ? \
  nums[0] * nums[1] * nums[2] : \
  nums[numsSize-1] * nums[numsSize-2] * nums[0];

}

int main (void) {

 return 0;
}
