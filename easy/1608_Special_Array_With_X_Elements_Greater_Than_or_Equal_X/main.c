#include <stdio.h>

int CMP (const void *a, const void *b) {
 return *(int*) a - *(int*) b;
}

int specialArray(int* nums, int numsSize) {

 qsort (nums, numsSize, sizeof(int), CMP);

 for (int exist = 1; exist <= numsSize; exist++) {

  int count = 0;
  for (int j = 0; j < numsSize; j++) {
   if (nums[j] >= exist) {
    count = numsSize - j;
    break;
   }
  }
  
  if (count == exist) return exist;
 }
    
 return -1;
}

int main (void) {
 
 return 0;
}
