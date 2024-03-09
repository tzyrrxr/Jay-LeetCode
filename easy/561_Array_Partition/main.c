#include <stdio.h>

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

int arrayPairSum(int* nums, int numsSize) {
  int ret = 0;

  QuickSort (nums, 0, numsSize-1);

  for (int i = 0; i < numsSize; i+=2) ret += nums[i];
  
  return ret;
}

int main (void) {

 return 0;
}
