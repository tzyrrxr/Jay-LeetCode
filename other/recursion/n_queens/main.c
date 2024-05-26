#include <stdio.h>

struct hTable {
 int key;
 UT_hash_handle hh;
};

bool h_exit (struct hTable *head, int key) {
 struct hTable *tmp;
 HASH_FIND_INT (head, &key, tmp);

 return tmp != NULL;

}

void h_set (struct hTable** head, int key) {
 if (!h_exit(*head, key)) {
  struct hTable *tmp = (struct hTable*) malloc(sizeof(struct hTable));
  tmp->key = key;
  HASH_ADD_INT(*head, key, tmp);
 } else {
  printf("The number \"%d\"is existed in the hash table.", key);
 }

}

void h_delete(struct hTable** head, int key) {
 struct hTable *tmp;
 HASH_FIND_INT(*head, &key, tmp);
 if (tmp) {
  HASH_DEL(*head, tmp);
  free(tmp);

 } else {
  printf("The number \"%d\" is not existed in the hash table.", key);

 }
}

int BT (int row, struct hTable *h_cols, struct hTable *h_diagonals, struct hTable *h_antiDiagonals, int n) {
 if (row == n) return 1; // Find the one of solutions.
                         
 int ret = 0; // the i-th row solution
              
 for (int col = 0; col < n; col++) {
  int diag = row - col; /* \ is the same. */
  int antiDiag = row + col; /* / is the same. */
  if (h_exit(h_cols, col) || h_exit(h_diagonals, diag) || h_exit(h_antiDiagonals, antiDiag)) continue;
  h_set(&h_cols, col);
  h_set(&h_diagonals, diag);
  h_set(&h_antiDiagonals, antiDiag);

  ret += BT(row+1, h_cols, h_diagonals, h_antiDiagonals, n);

  h_delete(&h_cols, col);
  h_delete(&h_diagonals, diag);
  h_delete(&h_antiDiagonals, antiDiag);

 }

 return ret;

}


int totalNQueens(int n) {
 int row = 0;
 int ret = 0;
 // h: hash
 struct hTable *h_cols = NULL; /* | */
 struct hTable *h_diagonals = NULL; /* \ */
 struct hTable *h_antiDiagonals = NULL; /* / */

 ret = BT(row, h_cols, h_diagonals, h_antiDiagonals, n);
    
 return ret;

}

int main (void) {
 
 return 0;
}
