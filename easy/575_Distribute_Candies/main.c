#include <stdio.h>

void QuickSort (int *candyType, int left, int right) {
 if (left >= right) return;
 int pivot = candyType[left];
 int l = left + 1;
 int r = right;
 int tmp;

 for (;l <= r;) {
  for (;l <= right && candyType[l] <= pivot; l++);
  for (;left < r && candyType[r] >= pivot; r--);

  if (l <= r) {
   tmp = candyType[l];
   candyType[l] = candyType[r];
   candyType[r] = tmp;
  }
 }

 tmp = candyType[left];
 candyType[left] = candyType[r];
 candyType[r] = tmp;

 QuickSort (candyType, left, r-1);
 QuickSort (candyType, r+1, right);
}

int distributeCandies(int* candyType, int candyTypeSize) {

 int canEat = candyTypeSize/2 - 1;
 int maxType = 1;
 int probeType;

 QuickSort(candyType, 0, candyTypeSize -1);

 probeType = candyType[0];

 for (int i = 1; i < candyTypeSize && canEat > 0; i++) {
  if (probeType != candyType[i]) {
   maxType++;
   canEat--;
   probeType = candyType[i];
  }
 }

 return maxType;
}

int main (void) {

 return 0;
}
