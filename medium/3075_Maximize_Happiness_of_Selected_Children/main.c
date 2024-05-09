#include <stdio.h>

int CMP(const void *a, const void *b) {
 return *(int*) b - *(int*) a;
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
 int turns = 0;
 int val = INT_MAX;
 long long ret = 0;
 int tmp;
 qsort (happiness, happinessSize, sizeof(int), CMP);

 for (int i = 0; i < k; i++, turns++) {
  val = happiness[i] - turns;
  if (val <= 0) return ret;
  ret += val;
 }
    
 return ret;
}

int main (void) {

 return 0;
}
