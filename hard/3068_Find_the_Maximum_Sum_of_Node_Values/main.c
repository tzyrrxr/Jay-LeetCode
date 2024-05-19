#include <stdio.h>
#include <limits.h>

// a XOR b XOR b == a --> Item b is the even item
// a XOR a == 0
long long maxSumOfNodes (int *nums, int numsSize, int k, int index, int isEven, long long **memo) {
 if (index == numsSize) {
  return isEven == 1 ? 0 : INT_MIN;
 }
 // DP
 // if the item is memoried, return its value
 if (memo[index][isEven] != -1) return memo[index][isEven];

 long long noXORIndex = nums[index] + maxSumOfNodes (nums, numsSize, k, index+1, isEven, memo);
 long long XORIndex = nums[index]^k + maxSumOfNodes (nums, numsSize, k, index+1, isEven^1, memo); // 0^1 == 1, 1^1 == 0

 // memoried the item
 return memo[index][isEven] = noXORIndex < XORIndex ? XORIndex : noXORIndex;
}

long long maximumValueSum(int* nums, int numsSize, int k, int** edges, int edgesSize, int* edgesColSize) {
 long long **memo = (long long **) malloc(numsSize * sizeof(long long*));
 for (int i = 0; i < numsSize; i++) {
  memo[i] = (long long *) malloc(2 * sizeof(long long));
  memo[i][0] = -1;
  memo[i][1] = -1;
 }

 return maxSumOfNodes(nums, numsSize, k, 0, 1, memo);
    
}

int main (void) {

 return 0;
}
