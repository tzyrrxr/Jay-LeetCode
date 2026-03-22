bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    int mm = matSize;
    int mn = *matColSize;
    
    int tm = targetSize;
    int tn = *targetColSize;

    bool res = true;
    
    // 0
    for (int i = 0; i < mm && res == true; i++) {
        for (int j = 0; j < mm; j++) {
            if (target[i][j] != mat[i][j]) {
                res = false;
                break;
            }
        }
    }
    if (res == true) return res;
    else res = true;
    
    // 90
    for (int i = 0, mj = mn-1; i < mm && mj >= 0 && res == true; i++, mj--) {
        for (int j = 0, mi = 0; j < mm, mi < mm; j++, mi++) {
            if (target[i][j] != mat[mi][mj]) {
                res = false;
                break;
            }
        }
    }
    if (res == true) return res;
    else res = true;

    // 180
    for (int i = 0, mi = mm-1; i < mm && mi >= 0 && res == true; i++, mi--) {
        for (int j = 0, mj = mn-1; j < mm, mj >= 0; j++, mj--) {
            if (target[i][j] != mat[mi][mj]) {
                res = false;
                break;
            }
        }
    }
    if (res == true) return res;
    else res = true;

    // 270
    for (int i = 0, mj = 0; i < mm && mj < mn && res == true; i++, mj++) {
        for (int j = 0, mi = mm-1; j < mm, mi >= 0; j++, mi--) {
            if (target[i][j] != mat[mi][mj]) {
                res = false;
                break;
            }
        }
    }
    
    return res;

}