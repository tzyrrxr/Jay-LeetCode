long long maxProfit(int* prices, int pricesSize, int* strategy, int strategySize, int k) {
  long long max = -1e18; // -1e18 is double percision
  long long sum = 0;
  long long base = 0;
  long long mem;

  for (int i = 0; i < pricesSize; i++) base += prices[i] * strategy[i]; 
  if (max < base) max = base;

  mem = base;
  for (int i = 0; i+k <= pricesSize; i++) {
    // the first half --> strategy to hold (0)
    for (int j = i; j < i+k/2; j++) {
      if (strategy[j] != 0) {
        base -= prices[j] * strategy[j];
      }
    }

    // the last half --> strategy to sell (1)
    for (int j = i+k/2; j < i+k; j++) {
      if (strategy[j] == 0) {
        base += prices[j]; 
      } else if (strategy[j] == -1) {
        base -= prices[j] * strategy[j];
        base += prices[j]; 
      }
    }

    if (max < base) max = base;
    base = mem;

  }

  return max;

}
