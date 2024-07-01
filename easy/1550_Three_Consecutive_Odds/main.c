#include <stdio.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
  int x, y, z;
  x = 0;
  y = 1;
  z = 2;
  for (; z < arrSize; x++, y++, z++) {
    if (arr[x] % 2 && arr[y] % 2 && arr[z] % 2) return true;
  }

  return false;
    
}

int main (void) {
 
 return 0;
}
