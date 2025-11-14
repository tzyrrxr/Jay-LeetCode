#include <stdio.h>
#include <stdlib.h>

#define D1(r,c) ((r)*(n+1) + (c))

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** rangeAddQueries(
  int n, 
  int** queries, 
  int queriesSize, 
  int* queriesColSize, 
  int* returnSize, 
  int** returnColumnSizes) 
{
  int** ret;
  int* diff; //convert 2D to 1D for difference matrix

  // allocate memory for row
  ret = (int**) calloc(n, sizeof(int*));

  // allocate size for row
  //returnSize = (int*) malloc(sizeof(int));
  *returnSize = n;

  // allocate size for column
  *returnColumnSizes = (int*) malloc(sizeof(int)*n);

  for (int i = 0; i < n; i++) {
    // allocate memory for column
    ret[i] = (int*) calloc (n, sizeof(int));
    // allocate size for column
    (*returnColumnSizes)[i] = n;
  }


  diff = (int*) calloc((n+1)*(n+1), sizeof(int));
  for (int i = 0; i < queriesSize; i++) {
    int r1 = queries[i][0];
    int c1 = queries[i][1];
    int r2 = queries[i][2];
    int c2 = queries[i][3];

    diff[D1(r1, c1)]     += 1;
    diff[D1(r1, c2+1)]   -= 1;
    diff[D1(r2+1, c1)]   -= 1;
    diff[D1(r2+1, c2+1)] += 1;
  }

  // prefix sum for column
  for (int r = 0; r < n; r++) {
    for (int c = 1; c < n; c++) {
      diff[D1(r,c)] += diff[D1(r, c-1)];
    }
  }

  // prefix sum for row
  for (int c = 0; c < n; c++) {
    for (int r = 1; r < n; r++) {
      diff[D1(r,c)] += diff[D1(r-1, c)];
    }
  }

  // write into ret
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      ret[r][c] = diff[D1(r,c)];
    }
  }

  free(diff);

   
  return ret;

}
