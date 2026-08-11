bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    int n = matSize;
    int res = 0b1111;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((res & 0b1000) && target[i][j] != mat[i][j]) res &= 0b0111;
            if ((res & 0b0100) && target[i][j] != mat[j][n-i-1]) res &= 0b1011;
            if ((res & 0b0010) && target[i][j] != mat[n-i-1][n-j-1]) res &= 0b1101;
            if ((res & 0b0001) && target[i][j] != mat[n-j-1][i]) res &= 0b1110;
            if (res == 0b0000) return false;
        }
    }
    
    return res != 0;

}