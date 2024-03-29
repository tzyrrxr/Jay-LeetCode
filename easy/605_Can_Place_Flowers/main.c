#include <stdio.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
 if (flowerbedSize == 1 && !flowerbed[0]) return true;

 for (int i = 0; i < flowerbedSize && n > 0; i++) {
  if (flowerbed[i]) continue;

  if (i != 0 && i != flowerbedSize-1) {
   if ((flowerbed[i-1] | flowerbed[i+1]) == 0) {
    flowerbed[i]++;
    n--;
   }
  } else if (i == 0) {
   if (flowerbed[i+1] == 0) {
    flowerbed[i]++;
    n--;
   }
  } else {
   if (flowerbed[i-1] == 0) {
    flowerbed[i]++;
    n--;
   }
  }

 }

 return n == 0;
}

int main (void) {

 return 0;
}
