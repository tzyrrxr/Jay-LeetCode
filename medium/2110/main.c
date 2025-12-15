long long getDescentPeriods(int* prices, int pricesSize) {
  int cnt = 0; 
  int len = pricesSize;

  // brute force
  for (int i = 0; i < len; i++) {
    for (int j = i; j < len-1; j++) {
      if (j == i) cnt++; // itself
      if (prices[j]-1 == prices[j+1]) {
        cnt++;
      } else {
        break;
      }
    }
  }

  cnt++; // the last one
         
  return cnt;

}
