// 1. Return the largest "square" area
// 2. hBars and vBars are unsorted array

int CMP(const void *a, const void *b) { return *(int*)a - *(int*)b; }

int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize) {
  int side = 1; 
  int hcurr = 1, vcurr = 1;
  int hmax = 1, vmax = 1;

  qsort(hBars, hBarsSize, sizeof(int), CMP);
  qsort(vBars, vBarsSize, sizeof(int), CMP);

  // Count the left length first.
  for (int i = 1; i < hBarsSize; i++) {
    if (hBars[i] - hBars[i-1] == 1) {
      hcurr += 1;
    } else {
      hcurr = 1;
    }
    hmax = fmax (hmax, hcurr);
  }
    
  // Count the top length first.
  for (int i = 1; i < vBarsSize; i++) {
    if (vBars[i] - vBars[i-1] == 1) {
      vcurr += 1;
    } else {
      vcurr = 1;
    }
    vmax = fmax (vmax, vcurr);
  }

  // Add the length of right or bottom side.
  side = fmin (hmax, vmax) + 1;

  return side * side;
}
