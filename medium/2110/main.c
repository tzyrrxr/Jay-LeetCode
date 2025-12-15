long long getDescentPeriods(int* prices, int pricesSize) {
  long long cnt = 1; 
  int smoothDes = 1;

  // counting as long as possible
  // compute the summation simultaneously
  for (int i = 1; i < pricesSize; i++) {
    if (prices[i-1] - 1 == prices[i]) {
      smoothDes++;
    } else {
      smoothDes = 1;
    }
    cnt += smoothDes;
  }
         
  return cnt;

}
