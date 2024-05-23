#include <stdio.h>

int CMP (const void *a, const void *b) {
 return *(int*)a - *(int*)b;
}

int Count (int *nums, int len, int diff, int *hash, int index) {

 if (index == len) return 1;
 int totalCount = 0;

 totalCount = Count (nums, len, diff, hash, index+1); // mark status

 int exist = nums[index] - diff;
 int val = nums[index];
 if (exist < 0 || hash[exist] == 0) {
  hash[val]++;
  totalCount += Count(nums, len, diff, hash, index + 1); // backtracking
  hash[val]--;
 }

 return totalCount;

}

int beautifulSubsets(int* nums, int numsSize, int k) {
 int ret = 0;
 int len = numsSize;
 int numsIndex = 0;
 int maxVal = INT_MIN;
 int diff = k;



 qsort (nums, len, sizeof(int), CMP);
 maxVal = nums[len-1];

 int *hash = (int *) calloc(maxVal+1, sizeof(int));

 ret = Count(nums, numsSize, diff, hash, numsIndex);
 ret--; // remove []
 
 free(hash);

 return ret;
    
}

int main (void) {
 
 return 0;
}
