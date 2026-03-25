bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = *gridColSize;
    long long total = 0;
    long long tmpSum = 0;
    
    long long rowVal[m];
    long long colVal[n];

    for (int i = 0; i < m; i++) {
        long long tmp = 0;
        for (int j = 0; j < n; j++) {
            total += grid[i][j];
            tmp += grid[i][j];
        }
        rowVal[i] = tmp;
    }

    if (total & 0x1) {
        return false;
    }

    long long target = total / 2;

    for (int i = 0; i < n; i++) {
        long long tmp = 0;
        for (int j = 0; j < m; j++) {
            tmp += grid[j][i];
        }
        colVal[i] = tmp;
        tmpSum += colVal[i];
        if (tmpSum == target) {
            return true;
        }
    }
    tmpSum = 0;
    for (int i = 0; i < m; i++) {
        tmpSum += rowVal[i];
        if (tmpSum == target) {
            return true;
        }
    }
    
    return false;
    
}