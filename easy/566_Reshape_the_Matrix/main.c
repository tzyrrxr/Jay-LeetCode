#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
  if (r*c != matSize*(*matColSize)) {
    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    return mat;
  }
  int **ret;
  int total = matSize * (*matColSize);

  ret = (int**) malloc(r * sizeof(int*));
  *returnColumnSizes = (int*) malloc(r * sizeof(int));
  for (int i = 0; i < total; i++) {
    if (i%c == 0) {
      ret[i / c] = (int*) malloc(c * sizeof(int));

      (*returnColumnSizes)[i / c] = c;
    }

    ret[i/c][i%c] = mat[i/(*matColSize)][i%(*matColSize)];

  }

  *returnSize = r;

  return ret;
}

int main (void) {

 return 0;
}
