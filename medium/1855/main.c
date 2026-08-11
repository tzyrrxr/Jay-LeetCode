int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int i = 0;
  int j = 0;
  int max = 0;
  while (i < nums1Size && j < nums2Size) {
    if (nums1[i] > nums2[j]) {
      i++;
    } else {
      if (j-i > max) {
        max = j - i;
      }
      j++;
    }
  }
    
  return max;
}
