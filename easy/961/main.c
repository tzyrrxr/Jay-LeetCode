int repeatedNTimes(int* nums, int numsSize) {
  int hash[10001] = {0};
  for (int i = 0; i < numsSize; i++) {
    if (hash[nums[i]] == 1) {
      return nums[i];
    }
    hash[nums[i]]++;
  }

  return -1;

}
