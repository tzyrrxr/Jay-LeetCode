// brute method
bool areSimilar(int** mat, int matSize, int* matColSize, int k) {

    int m = matSize;
    int n = *matColSize;
    k = k % n;
    if ( k == 0) return true;

    int test[m][n];
    
    for (int i = 0; i < m; i++) {
        memcpy(test[i], mat[i], sizeof(int)*n);
    }
    
    for (int t = 0; t < k; t++) {
        int tmp;
        for (int i = 0; i < m; i += 2) {
            tmp = test[i][0];
            int j;
            for (j = 0; j < n-1; j++) {
                test[i][j] = test[i][j+1];
            }
            test[i][j] = tmp; 
        }

        for (int i = 1; i < m; i += 2) {
            tmp = test[i][n-1];
            int j;
            for (j = n-1; j > 0; j--) {
                test[i][j] = test[i][j-1];
            }
            test[i][0] = tmp; 
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != test[i][j]) return false;
        }
    }

    return true;

}