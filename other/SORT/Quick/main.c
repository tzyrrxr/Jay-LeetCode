#include <stdio.h>

void QuickSort(int *arr, int left, int right) {
  if (left >= right) return;

  int pivotIndex = left;
  int sortOfLeftIndex = left + 1;
  int sortOfRightIndex = right;

  for (;sortOfLeftIndex <= sortOfRightIndex;) {
    // finding the exchange index
    for (; sortOfLeftIndex <= right && arr[sortOfLeftIndex] <= arr[pivotIndex];sortOfLeftIndex++);
    for (;sortOfRightIndex > left+1 && arr[sortOfRightIndex] >= arr[pivotIndex];sortOfRightIndex--);
    if (sortOfLeftIndex <= sortOfRightIndex) {
      arr[sortOfLeftIndex] = arr[sortOfLeftIndex] + arr[sortOfRightIndex];
      arr[sortOfRightIndex] = arr[sortOfLeftIndex] - arr[sortOfRightIndex];
      arr[sortOfLeftIndex] = arr[sortOfLeftIndex] - arr[sortOfRightIndex];
    }
  }
  // exchange pivot value and meet index
  arr[left] = arr[left] + arr[sortOfRightIndex];
  arr[sortOfRightIndex] = arr[left] - arr[sortOfRightIndex];
  arr[left] = arr[left] - arr[sortOfRightIndex];

  QuickSort (arr, left, sortOfRightIndex-1);
  QuickSort (arr, sortOfRightIndex+1, right);

}

int main (void) {

  // test
  int arr[] = {6,2,6,5,1,2};
  QuickSort (arr, 0, 5);

  return 0;
}
