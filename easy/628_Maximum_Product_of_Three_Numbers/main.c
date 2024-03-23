#include <stdio.h>

void QuickSort(int *arr, int left, int right) {
  if (left >= right) return;

  int pivotIndex = left;
  int sortOfLeftIndex = left + 1;
  int sortOfRightIndex = right;
  int tmp;

  for (;sortOfLeftIndex <= sortOfRightIndex;) {
    // finding the exchange index
    for (; sortOfLeftIndex <= right && arr[sortOfLeftIndex] >= arr[pivotIndex];sortOfLeftIndex++);
    for (;sortOfRightIndex > left && arr[sortOfRightIndex] <= arr[pivotIndex];sortOfRightIndex--);
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
int maximumProduct(int* nums, int numsSize) {
 if (numsSize == 3) return nums[0]*nums[1]*nums[2];

 //// bubble sort
 //for (int i = 0; i < numsSize; i++) {
 // for (int j = 0; j < numsSize-1-i; j++) {
 //  if (nums[j] < nums[j+1]) {
 //   int tmp = nums[j];
 //   nums[j] = nums[j+1];
 //   nums[j+1] = tmp;
 //  }
 // }
 //}
 
 // Quick Sort
 QuickSort (nums, 0, numsSize-1);

 return nums[0] * nums[1] * nums[2] > nums[numsSize-1] * nums[numsSize-2] * nums[0] ? \
  nums[0] * nums[1] * nums[2] : \
  nums[numsSize-1] * nums[numsSize-2] * nums[0];

}

int main (void) {

 return 0;
}
