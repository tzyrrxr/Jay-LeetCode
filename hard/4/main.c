#include <stdio.h>

// Target: get median number from merge of two sorted arrays
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int *a = nums1;
  int *b = nums2;
  int aLen = nums1Size;
  int bLen = nums2Size;
  int pA = 0;
  int pB = 0;
  int mergeLen = aLen + bLen;
  int curr = 0;
  int prev = 0;

  for (int i = 0; i <= mergeLen/2.0; i++) {
    prev = curr;

    // Be careful: nums1 or nums2 maybe empty. Check length first
    if (pA < aLen && (pB >= bLen || a[pA] <= b[pB])) {
      curr = a[pA++];
    } else {
      curr = b[pB++];
    }
  }

  if (mergeLen & 1) { // odd
    return curr;
  }

  // even
  return (double)((curr + prev)/2.0);
  
}
