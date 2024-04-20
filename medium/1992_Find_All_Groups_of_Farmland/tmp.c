/*
 * m == row
 * n == col
 */

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void DFS (int **land, int rLen, int cLen, int y, int x, int* ret) {
 int dx, dy;
 land[y][x] = -1; // visited

 if (x < ret[0]) ret[0] = x;
 if (y < ret[1]) ret[1] = y;
 if (ret[2] < x) ret[2] = x;
 if (ret[3] < y) ret[3] = y;

 for (int d = 0; d < 4; d++) {
  dx = x + dir[d][0];
  dy = y + dir[d][1];

  if (dx >= 0 && dx < cLen &&
      dy >= 0 && dy < rLen &&
      1 == land[dy][dx] 
      ) {
    DFS (land, rLen, cLen, dy, dx, ret);
  }

 }

}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findFarmland(int** land, int landSize, int* landColSize, int* returnSize, int** returnColumnSizes) {
 int **ret = (int**)malloc(landSize * sizeof(int*));
 int rLen = landSize;
 int cLen = *landColSize;
 int *tmp;

 *returnSize = 0;
 *returnColumnSizes = (int*) malloc(landSize * sizeof(int));

 for (int r = 0; r < rLen; r++) {
  for (int c = 0; c < cLen; c++) {
   if (1 == land[r][c]) {
    ret[(*returnSize)] = (int*) calloc(4, sizeof(int));
    ret[(*returnSize)][0] = INT_MAX;
    ret[(*returnSize)][1] = INT_MAX;
    ret[(*returnSize)][2] = INT_MIN;
    ret[(*returnSize)][3] = INT_MIN;


    DFS (land, rLen, cLen, r, c, ret[(*returnSize)]);
    (*returnColumnSizes)[(*returnSize)] = 4;
    (*returnSize)++;
   }
  }
 }
 
 return ret;
}
