#include <stdio.h>

int maxFrequencyElements(int* nums, int numsSize) {
  int hash[101] = {0};
  int maxFreq[101] = {0};
  int len = numsSize;
  int max = 0;
  int sum = 0;

  while (len--) {
    hash[nums[len]]++;
  }

  len = 101;
  while (len--) {
    max = hash[len] > max ? hash[len] : max;
  }

  len = 101;
  while (len--) {
    if (hash[len] == max) {
      sum += hash[len];
    }
  }

  return sum;
    
}
