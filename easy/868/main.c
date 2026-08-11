int binaryGap(int n) {
  int cnt = 0;
  int max = 0;

  while (!(n&1) && n > 0) {
    n >>= 1;
  }
    
  while (n) {
    n >>= 1;
    cnt++;
    if (n&1) {
      max = (cnt > max) ? cnt: max;
      cnt = 0;
    }
  }

  return max;
}
