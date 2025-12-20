// prefix sum method
long long maxProfit(int* prices, int pricesSize, int* strategy, int strategySize, int k) {
  long long max = -1e18; // -1e18 is double percision
  long long *profitSum = (long long *) calloc(pricesSize+1, sizeof(long long));
  long long *pricesSum = (long long *) calloc(pricesSize+1, sizeof(long long));

  for (int i = 0; i < pricesSize; i++) {
    profitSum[i+1] = profitSum[i] + prices[i] * strategy[i]; 
    pricesSum[i+1] = pricesSum[i] + prices[i];
  }

  max = profitSum[pricesSize];


  // {{leftProfit}, {consecutive k profit}, {rightProfit}}
  // Total profit = leftProfit + consecutive k profit + rightProfit
  for (int i = k-1; i < pricesSize; i++) {
    long long leftProfit = profitSum[i-k+1];
    long long consecutiveProfit = pricesSum[i+1] - pricesSum[i- k/2 +1];
    long long rightProfit = profitSum[pricesSize] - profitSum[i+1];
    if (max < leftProfit + consecutiveProfit + rightProfit) {
      max = leftProfit + consecutiveProfit + rightProfit;
    }
  }

  return max;

}
