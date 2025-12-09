#include <stdio.h>

#define M_HASH_SPCE 1000000// 10^6
#define MOD 1000000007 // 10^9+7 prevent overflow

int specialTriplets(int* nums, int numsSize) {
  unsigned int cnt = 0;
  unsigned long long  *numCntHash = (long long*) calloc(M_HASH_SPCE, sizeof(long long));
  unsigned long long *midNumHash = (long long*) calloc(M_HASH_SPCE, sizeof(long long));;

  for (int i = 0; i < numsSize; i++) {
    int Number = nums[i];
    if (((int)Number & 1) == 0) cnt = (cnt + midNumHash[Number/2])%MOD;
    // numCntHash -> different index of nums to count
    midNumHash[Number] = (midNumHash[Number] + numCntHash[Number * 2])%MOD; // there is a match if count of numCntHash exist.
    numCntHash[Number]++;
  }

  return cnt;
    
}
