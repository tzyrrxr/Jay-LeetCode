#include <stdlib.h>
#include <math.h>

// histogram
int maximalRectangle(char** matrix, int matrixsize, int* matrixcolsize) {
  int w = *matrixcolsize;
  int h = matrixsize;
  int *continuousH = (int *) calloc(w, sizeof(int)); // record continuous height
  int maxArea = INT_MIN;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      continuousH[j] = (matrix[i][j] == '1') ? continuousH[j]+1 : 0;
    }

    // get all of possible width
    for (int start = 0; start < w; start++) {
      int minH = INT_MAX;
      int maxW = INT_MIN;
      for (int end = start; end < w; end++) {
        // calculate area with histogram
        minH = fmin (minH, continuousH[end]);
        maxW = end - start + 1;
        maxArea = fmax(maxArea, minH*maxW);
      }
    }
  }
    
  free(continuousH);
  return maxArea;
}
