int CMP (const void *a, const void *b) {
  return *(int*) a - *(int*) b;
}

int minPairSum(int* nums, int numsSize){
  int max = INT_MIN;
  qsort (nums, numsSize, sizeof(int), CMP);

  for (int i=0, j=numsSize-1; i<j; i++, j--) {
    max = nums[i]+nums[j] > max ? nums[i]+nums[j] : max;
  }

  return max;

}
