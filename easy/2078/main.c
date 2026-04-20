int maxDistance(int* colors, int colorsSize) {
  int *c = colors;
  int n = colorsSize;
  int max = 0;

  for (int i = 0; i < n; i++) {
    for (int j = n-1; j > i; j--) {
      if (c[j] != c[i]) {
        max = fmax(j-i, max);
        break;
      }
    }
  }

  return max;
}
