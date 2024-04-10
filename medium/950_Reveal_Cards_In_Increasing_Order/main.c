#include <stdio.h>
#include <stdlib.h>

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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
 int *ret = (int *) malloc(deckSize * sizeof(int));
 int *IndiceQueue = (int *)malloc(deckSize * sizeof(int));
 int tmp;

 // determine the index order.
 for (int i = 0; i < deckSize; i++) IndiceQueue[i] = i;
 for (int i = 0; i < deckSize-1; i++) {
  tmp = IndiceQueue[i+1];
  for(int j = i+1; j < deckSize-1; j++) {
   IndiceQueue[j] = IndiceQueue[j+1];
  }
  IndiceQueue[deckSize-1] = tmp;
 }

 QuickSort (deck, 0, deckSize-1);

 for (int i = 0; i < deckSize; i++) {
  ret[IndiceQueue[i]] = deck[i];
 }
    
 free(IndiceQueue);
 *returnSize = deckSize;
 return ret;
}

int main (void) {

 int arr[] = {17,13,11,2,3,5,7};
 int size;
 deckRevealedIncreasing (arr, 7, &size);

 return 0;
}
