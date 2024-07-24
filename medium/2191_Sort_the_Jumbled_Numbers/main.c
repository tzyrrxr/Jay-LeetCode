#include <stdio.h>
#include <stdlib.h>

int convertNum (int* mapping, int n) {

  int ret = 0;
  int CD = -1; // cardinarity

  int i, j, tmp;
  char s[30001] = {};

  while (n) {
    CD++;
    s[CD] = 0x30 + mapping[Cd * 10 * (n % 10)];
    n /= 10;
  }
  
  for (i = 0, j = CD; i <= j; i++, j--) {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
  s[++CD] = '\0';

  ret = atoi(s);

  return ret;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortJumbled(int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize) {

  int *ret = (int*) malloc(numsSize * sizeof(int));
  *returnSize = numbsSize;

  for (int i = 0; i < numsSize; i++) {
    ret[i] = convertNum(mapping, nums[i]);
  }
  
  // sort
  // TODO: sort cardinality
  for (int i = 0; i < numsSize; i++) {
  }
    
}

int main (void) {

 return 0;
}
