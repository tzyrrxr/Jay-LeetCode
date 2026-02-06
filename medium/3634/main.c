int CMP (const void *a, const void *b) {
  return *(int*) a - *(int*)b;
}

int minRemoval(int* nums, int numsSize, int k) {
  int s = 0, e = 0;
  int maxRange = INT_MIN;
  qsort(nums, numsSize, sizeof(int), CMP);

  for (e = 0; e < numsSize; e++) {
     if (s <= e &&
         (long long)nums[e] > (long long)nums[s]*k
         ) {
       s++;
     }
     int currRange = e - s + 1;
     if (currRange > maxRange) maxRange = currRange;
  }

  return numsSize - maxRange;
}
