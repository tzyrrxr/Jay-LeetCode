#include <stdio.h>

// i < j
// nums1[i] + nums1[j] > nums2[i] + nums2[j]
// nums1[i] - nums2[i] > num2[j] - nums1[j]

long long countPairs(int* nums1, int nums1Size, int* nums2, int nums2Size) {
 long long ret = 0;
 int l, r;
 int len = nums1Size;
 
 for (int i = 0; i < len-1; i++) {
  for (int j = i+1; j < len; j++) {
   l = nums1[i] - nums2[i];
   r = nums2[j] - nums1[j];
   if (l > r) ret++;
  }
 }

 return ret;
}

int main (void) {

 return 0;
}
