/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define STONE '#'
#define OBSTACLE '*'
char** rotateTheBox(char** boxGrid, int boxGridSize, int* boxGridColSize, int* returnSize, int** returnColumnSizes) {
  char **box = boxGrid;
  int rows = boxGridSize;
  int cols = *boxGridColSize;

  // # stone 
  // * obstacle
  // . space
  for (int i = rows - 1; i >= 0; i--) {
    for (int j = cols -1; j >= 0; j--) {
      if (STONE == box[i][j] || OBSTACLE == box[i][j]) {
        continue;
      } else { // .
        for (int k = j-1; k >= 0 && box[i][k] != OBSTACLE; k--) {
          if (box[i][k] == STONE) {
            char tmp = box[i][k];
            box[i][k] = box[i][j];
            box[i][j] = tmp;
            break;
          } else if (OBSTACLE == box[i][k]){
            j = k;
          }
        }
      } 
    }
  }

  char **ret = (char**) malloc(cols * sizeof(char*));
  *returnSize = cols;
  (*returnColumnSizes) = (int *) malloc(cols*sizeof(int));

  for (int i = 0; i < cols; i++) {
    ret[i] = (char*) malloc(rows * sizeof(char));
    (*returnColumnSizes)[i] = rows;
  }

  for (int i = 0; i < rows ; i++) {
    for (int j = 0; j < cols; j++) {
     ret[j][rows-1-i] = box[i][j];
    }
  }

  return ret;
    
}
