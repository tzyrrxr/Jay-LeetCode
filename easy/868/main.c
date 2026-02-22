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
      if (cnt > max) {
        max = cnt;
      }
      cnt = 0;
    }
  }

  return max;
}
