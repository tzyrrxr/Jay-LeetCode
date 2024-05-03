#include <stdio.h>

void QuickSort(int *arr, int left, int right);

/*
 * i < j
 * nums1[i] + nums1[j] > nums2[i] + nums2[j]
 * nums1[i] - nums2[i] > nums2[j] - nums1[j]
 * (nums1[i] - nums2[i]) - (nums2[j] - nums1[j]) > 0
 *
 * (nums1[i] - nums2[i]) + (nums1[j] - nums2[j]) > 0
 * (nums1[j] - nums2[j]) + (nums1[i] - nums2[i]) > 0
 *
 * {left == i, right == j} or {left == j, right == i}
 * diff[left] + diff[right] > 0
 *
*/

long long countPairs(int* nums1, int nums1Size, int* nums2, int nums2Size) {
 long long ret = 0;
 int l, r;
 int len = nums1Size;
 int diff[len];
 int tmp;
 
 for (int z = 0; z < len; z++) {
  diff[z] = nums1[z] - nums2[z];
 }

 l = 0;
 r = len-1;

 QuickSort (diff, l, r);

 while (l < r) {
  tmp = diff[l] + diff[r];
  if (tmp > 0) {
   ret += r-l;
   r--;
  } else {
   l++;
  }
 }


 return ret;
}

void QuickSort(int *arr, int left, int right) {
  if (left >= right) return;

  int pivotIndex = left;
  int sortOfLeftIndex = left + 1;
  int sortOfRightIndex = right;
  int tmp;

  for (;sortOfLeftIndex <= sortOfRightIndex;) {
    // finding the exchange index
    for (; sortOfLeftIndex <= right && arr[sortOfLeftIndex] <= arr[pivotIndex];sortOfLeftIndex++);
    for (;sortOfRightIndex > left && arr[sortOfRightIndex] >= arr[pivotIndex];sortOfRightIndex--);
    if (sortOfLeftIndex <= sortOfRightIndex) {
      tmp = arr[sortOfLeftIndex];
      arr[sortOfLeftIndex] = arr[sortOfRightIndex];
      arr[sortOfRightIndex] = tmp;
    }
  }
  // exchange pivot value and meet index
  tmp = arr[left];
  arr[left] = arr[sortOfRightIndex];
  arr[sortOfRightIndex] = tmp;

  QuickSort (arr, left, sortOfRightIndex-1);
  QuickSort (arr, sortOfRightIndex+1, right);

}

int main (void) {

 return 0;
}
