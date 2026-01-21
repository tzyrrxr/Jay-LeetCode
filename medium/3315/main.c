/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
  int *res = (int *)malloc(numsSize * sizeof(int));

  // The prime number for binary of bit 0 position is always 1 except prime number 2.
  for (int i = 0; i < numsSize; i++) {
    int tmp = nums[i];
    int p = 1;
    for (p = 1; (tmp & p) != 0; p <<= 1);

    p >>= 1; // Move back to the last set bit position.
    res[i] = nums[i] == 2 ? -1 : tmp - p;
  }


  *returnSize = numsSize;
    
  return res;
}
