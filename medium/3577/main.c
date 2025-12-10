#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007 // prevent overflow

int countPermutations(int* complexity, int complexitySize) {
  unsigned long cnt = 1;
  int unlock;
  int min = INT_MAX;
  int *arr = complexity;
  int len = complexitySize;
  int factorial = len -1;

  unlock = arr[0];

  for (int i = 1; i < len; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  if (unlock >= min) {
    return 0;
  }
  while(factorial) {
    cnt = (unsigned long)((cnt * factorial) % MOD);
    factorial--;
  }

  return (int)cnt;

}
