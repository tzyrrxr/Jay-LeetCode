int CMP(const void*a, const void*b) {
   return *(int*) a - *(int*) b;
  }

int minimumDifference(int* nums, int numsSize, int k) {

  if (numsSize == 1) return 0;

  int diff = INT_MAX;
  qsort(nums, numsSize, sizeof(int), CMP);

  for (int i = 0; i+k-1 < numsSize; i++) {
    diff = fmin (diff, nums[i+k-1]-nums[i]);
  }
    
  return diff;

}
