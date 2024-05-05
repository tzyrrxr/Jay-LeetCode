#include <stdio.h>

void QS_inc (int *pt, int l, int r) {
 if (l >= r) return;

 int pivot = l;
 int lI = l + 1;
 int rI = r;
 int tmp;

 while (lI <= rI) {
  // search target
  while(lI <= r && pt[lI] <= pt[pivot]) lI++;
  while(l < rI && pt[pivot] <= pt[rI]) rI--;
  if (lI < rI) {
   tmp = pt[lI];
   pt[lI] = pt[rI];
   pt[rI] = tmp;
  }
  // exchange the pivot into the meet between left and right index
  tmp = pt[pivot];
  pt[pivot] = pt[rI];
  pt[rI] = tmp;

 }

 QS_inc (pt, l, rI-1);
 QS_inc (pt, rI+1, r);

}

void QS_dec (int *pt, int l, int r) {
 if (l >= r) return;

 int pivot = l;
 int lI = l + 1;
 int rI = r;
 int tmp;

 while (lI <= rI) {
  // search target
  while(lI <= r && pt[pivot] <= pt[lI]) lI++;
  while(l < rI && pt[rI] <= pt[pivot]) rI--;
  if (lI < rI) {
   tmp = pt[lI];
   pt[lI] = pt[rI];
   pt[rI] = tmp;
  }
  // exchange the pivot into the meet between left and right index
  tmp = pt[pivot];
  pt[pivot] = pt[rI];
  pt[rI] = tmp;

 }

 QS_dec (pt, l, rI-1);
 QS_dec (pt, rI+1, r);

}

void QuickSort_V1(int *arr, int left, int right) {
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
      //arr[sortOfLeftIndex] = arr[sortOfLeftIndex] + arr[sortOfRightIndex];
      //arr[sortOfRightIndex] = arr[sortOfLeftIndex] - arr[sortOfRightIndex];
      //arr[sortOfLeftIndex] = arr[sortOfLeftIndex] - arr[sortOfRightIndex];
      tmp = arr[sortOfLeftIndex];
      arr[sortOfLeftIndex] = arr[sortOfRightIndex];
      arr[sortOfRightIndex] = tmp;
    }
  }
  // exchange pivot value and meet index
  //arr[left] = arr[left] + arr[sortOfRightIndex];
  //arr[sortOfRightIndex] = arr[left] - arr[sortOfRightIndex];
  //arr[left] = arr[left] - arr[sortOfRightIndex];
    tmp = arr[left];
    arr[left] = arr[sortOfRightIndex];
    arr[sortOfRightIndex] = tmp;

  QuickSort_V1 (arr, left, sortOfRightIndex-1);
  QuickSort_V1 (arr, sortOfRightIndex+1, right);

}

int main (void) {

  // test
  int arr[] = {6,2,6,5,1,2};
  //QuickSort_V1 (arr, 0, 5);
  //QS_inc (arr, 0, 5);
  QS_dec (arr, 0, 5);
  puts("done");

  return 0;
}
