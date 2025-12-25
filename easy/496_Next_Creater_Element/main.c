int CMP (const void *a, const void *b) {
  return *(int*)b - *(int*)a;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int *res = (int*) malloc(nums1Size*sizeof(int));
  int *hash = (int*) calloc(10001, sizeof(int));
  int *sorted = (int*) malloc(nums2Size*sizeof(int));

  memset(res, -1, nums1Size*sizeof(int));
  memcpy(sorted, nums2, nums2Size*sizeof(int));
  qsort(sorted, nums2Size, sizeof(int), CMP);

  for (int i = 0; i < nums2Size; i++) {
    hash[nums2[i]] = i;
  }

  for (int i = 0; i < nums1Size; i++) {
    int elementIndex = hash[nums1[i]];
    for (int j = 0, nearest = INT_MAX; sorted[j] > nums1[i]; j++) {
      if (hash[sorted[j]] > elementIndex && hash[sorted[j]] - elementIndex < nearest) {
        res[i] = sorted[j];
        nearest = hash[sorted[j]] - elementIndex;
      }
    }
  }

  free(hash);
  free(sorted);

  *returnSize = nums1Size;
  return res;
    
}
