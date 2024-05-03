#include <stdio.h>

/*
 * i < j
 * nums1[i] + nums1[j] > nums2[i] + nums2[j]
 * nums1[i] - nums2[i] > num2[j] - nums1[j]
 * (nums1[i] - nums2[i]) - (num2[j] - nums1[j]) > 0
 * (nums1[i] - nums2[i]) + (num1[j] - nums2[j]) > 0
*/

long long countPairs(int* nums1, int nums1Size, int* nums2, int nums2Size) {
 long long ret = 0;
 int l, r;
 int len = nums1Size;
 int diff[len];
 
 for (int z = 0; z < len; z++) {
  diff[z] = nums1[z] - nums2[z];
 }

 return ret;
}

int main (void) {

 return 0;
}
