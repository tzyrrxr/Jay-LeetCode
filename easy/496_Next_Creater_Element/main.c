#include <stdio.h>
#include <stdlib.h>

//
// fail
//

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
 int *reSortNum2 = (int*) malloc((10000 + 1) * sizeof(int));
 int *ret = (int*) malloc(nums1Size * sizeof(int));

 for(int i = 1; i < nums2Size; i++) {
  if (nums2[i] > nums2[i-1]) {
   reSortNum2[nums2[i-1]] = nums2[i];
  } else {
   reSortNum2[nums2[i-1]] = -1;
  }
 }
 reSortNum2[nums2[nums2Size-1]] = -1;

 for (int i = 0; i < nums1Size; i++) {
  ret[i] = reSortNum2[nums1[i]];
 }

 *returnSize = nums1Size;
 free(reSortNum2);

 return ret;
}

int main (int argc, char *argv[]) {
 int n1[] = {4, 1, 2};
 int n2[] = {1, 3, 4, 2};
 int n1Size;
 nextGreaterElement(n1, 3, n2, 4, &n1Size);

 return 0;
}
