int getMinDistance(int* nums, int numsSize, int target, int start) {
  int min = INT_MAX;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == target) {
      if (start >= i) {
        min = fmin(min, start - i);
      } else {
        min = fmin(min, i - start);
      }
    }
  }
    
  return min;
}
