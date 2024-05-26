#include <stdio.h>

void BT (int row, bool *h_cols, bool *h_diagonals, bool *h_antiDiagonals, int n, int *count) {
    if (row == n) (*count)++; // find the one of the solution and count it.
    
    for (int col = 0; col < n; col++) {
        int diagonals = row - col + n;
        int antiDiagonals = row + col;
        if (!h_cols[col] && !h_diagonals[diagonals] && !h_antiDiagonals[antiDiagonals]) {
            h_cols[col] = 1;
            h_diagonals[diagonals] = 1;
            h_antiDiagonals[antiDiagonals] = 1;
            
            BT (row + 1, h_cols, h_diagonals, h_antiDiagonals, n, count);
                
            h_cols[col] = 0;
            h_diagonals[diagonals] = 0;
            h_antiDiagonals[antiDiagonals] = 0;
                
        }
    
    }

}


int totalNQueens(int n) {
    int row = 0;
    int ret = 0;
    bool *h_cols = (bool*) calloc(2*n, sizeof(bool));
    bool *h_diagonals = (bool*) calloc(2*n, sizeof(bool));
    bool *h_antiDiagonals = (bool*) calloc(2*n, sizeof(bool));
    
    BT (row, h_cols, h_diagonals, h_antiDiagonals, n, &ret);
    
    return ret;
    
}

int main (void) {
 
 return 0;
}
