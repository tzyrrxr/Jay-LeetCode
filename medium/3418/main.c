int maximumAmount(int** coins, int coinsSize, int* coinsColSize) {
  int m = coinsSize;
  int n = *coinsColSize;
  int dp[m][n][3];

  // init DP table
  dp[0][0][0] = coins[0][0];
  dp[0][0][1] = dp[0][0][2] = fmax(coins[0][0], 0);

  // init the first row
  for (int j = 1; j < n; j++) {
    dp[0][j][0] = dp[0][j-1][0] + coins[0][j];

    for (int k = 1; k <= 2; k++) {
      dp[0][j][k] = fmax(
          dp[0][j-1][k] + coins[0][j], // get score
          dp[0][j-1][k-1] + fmax(coins[0][j], 0) // pass
          );
    }
  }

  // init the first column
  for (int i = 1; i < m; i++) {
    dp[i][0][0] = dp[i-1][0][0] + coins[i][0];

    for (int k = 1; k <= 2; k++) {
      dp[i][0][k] = fmax(
          dp[i-1][0][k] + coins[i][0],
          dp[i-1][0][k-1] + fmax(coins[i][0], 0)
          );
    }
  }

  // start filling DP table
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j][0] = fmax(dp[i-1][j][0], dp[i][j-1][0]) + coins[i][j]; // choose left or top, then get score

      for (int k = 1; k <=2; k++) {
        dp[i][j][k] = fmax(
            fmax(dp[i-1][j][k], dp[i][j-1][k]) + coins[i][j], // choose left or top, then get score
            fmax(dp[i-1][j][k-1], dp[i][j-1][k-1])
            );
      }

    }
  }
    
  return dp[m-1][n-1][2];
}
