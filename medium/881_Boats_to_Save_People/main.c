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


int numRescueBoats(int* people, int peopleSize, int limit) {
 int ret = 0;
 int i, j;
 i = 0;
 j = peopleSize-1;

 QuickSort (people, 0, peopleSize-1);


 while (i <= j) {
  ret++;
  if (people[i++] + people[j] <= limit) j--;
 }

 return ret;
}

int main (void) {

 //int arr[] = {2338,2197,12607,16524,22227,4269,12666,19109,2537,13345,11078,28468,1736,12259,12517,21846,9621,6120,8800,14127,28509,23896,8310,16746,20647,23870,13385,11964,23030,12952,7439,13604,28114,4278,13874,19120,14499,6110,56,20970,18563,234,8957,23060,18868,16357,4687,21189,14144,20346};
 int arr[] = {5,1,4,2};
 numRescueBoats (arr, sizeof(arr)/sizeof(int), 6);

 return 0;
}
