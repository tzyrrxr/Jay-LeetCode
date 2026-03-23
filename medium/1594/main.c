#define MOD 1000000007

int maxProductPath(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = *gridColSize;
    long long max_dp[m][n];
    long long min_dp[m][n];
    max_dp[0][0] = grid[0][0];
    min_dp[0][0] = grid[0][0];
    
    for (int i = 1; i < m; i++) {
        max_dp[i][0] = max_dp[i-1][0] * grid[i][0];
        min_dp[i][0] = min_dp[i-1][0] * grid[i][0];
    }
    for (int j = 1; j < n; j++) {
        max_dp[0][j] = max_dp[0][j-1] * grid[0][j];
        min_dp[0][j] = min_dp[0][j-1] * grid[0][j];
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            max_dp[i][j] = fmax (
                fmax(max_dp[i-1][j]*grid[i][j], min_dp[i-1][j]*grid[i][j]),
                fmax(max_dp[i][j-1]*grid[i][j], min_dp[i][j-1]*grid[i][j])
            );
            min_dp[i][j] = fmin (
                fmin(max_dp[i-1][j]*grid[i][j], min_dp[i-1][j]*grid[i][j]),
                fmin(max_dp[i][j-1]*grid[i][j], min_dp[i][j-1]*grid[i][j])
            );
        }
    }
    
    return max_dp[m-1][n-1] < 0 ? -1 : (max_dp[m-1][n-1]%MOD);
}