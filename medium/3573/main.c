long long MAX (long long a, long long b) {
  return a > b ? a : b;
}

// short selling transaction 賣空: 先賣沒有持有的股票，之後再買回來.
//
// * 當沒有持有stock, 也沒有 short selling, 買進賣出算一次transaction
// * 當沒有持有stock, 也沒有 short selling, 賣出買進算一次transaction

// the variable k represents maximum count of transactions.
//
// 3 types, 
// The first one is that end of day is neithor holding a stock nor a short selling transaction
// The second one is that end of day is holding a stock. 
// The third one is that end of day is a short selling transaction
//
// Target: get the most profit without holding any stock and short selling transaction in the last day.
//
// Dynamic programming
// DP table 
//    DP[day][transaction][type]
//
// Count transactions when buying or do short selling a stock.
// notice: [transaction] means using at most transactions status.
long long maximumProfit(int* prices, int pricesSize, int k) {
  int days = pricesSize;
  int transaction = k;
  long long DP[days][transaction+1][3]; // the transaction starts with 1
  memset(DP, 0, sizeof(DP)); // all deals are zero.

  // Initialize DP table 
  // DP[0][i][0] = 0 
  for (int i = 1; i <= transaction; i++) {
    DP[0][i][1]= 0 - (long long) prices[0]; // buy a stock
    DP[0][i][2]= 0 + (long long) prices[0]; // do short selling transaction
  }

  for (int i = 1; i < days; i++) {
    for (int j = 1; j <= transaction; j++) {
      // Buy stock or not
      DP[i][j][1] = MAX (
                         DP[i-1][j][1], // No action and keep status 
                         DP[i-1][j-1][0] - prices[i] // Buy a stock
                        );

      // Do short selling transaction or not
      DP[i][j][2] = MAX (
                         DP[i-1][j][2], // No action and keep status 
                         DP[i-1][j-1][0] + prices[i] // Do short selling transaction
                        );

      // neither holding a stock and a short selling transaction
      // MAX (No action, MAX(hold a stock then sell it, Have a short selling transaction then buy a stock))
      DP[i][j][0] = MAX (
                      DP[i-1][j][0], // No action and keep status
                      MAX(
                        DP[i-1][j][1] + prices[i], // sell a stock, finish a transaction
                        DP[i-1][j][2] - prices[i]  // buy a stock, finish a transaction
                         )
                        );
      
    }
  }

  // Target: get the most profit without holding any stock and short selling transaction in the last day.
  // index of day start from 0. So the last day is "days-1".
  return (long long) DP[days-1][transaction][0];

}
