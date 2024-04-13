#include <stdio.h>

// Think about histogram
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
 unsigned int maxArea = 0;

 unsigned int minH = INT_MAX; // align other height
 unsigned int w = 0; // width of column

 unsigned int *histogramH = (unsigned int *) malloc(*matrixColSize * sizeof(unsigned int));
 for (int c = 0; c < *matrixColSize; c++) histogramH[c] = 0;

 //(unsigned int *) calloc(histogramH, *matrixColSize * sizeof(unsigned int));

 for (int r = 0; r < matrixSize; r++) {
  // if the cell is zero, then we need to reset the histogram.
  for (int c = 0; c < *matrixColSize; c++) histogramH[c] = matrix[r][c] == '1' ? histogramH[c] + 1 : 0;

  // determine the area
  for (int c = 0; c < *matrixColSize; c++) {
   /*
    * The same row and find the minimal of heigh and multiple width that is equal to area.
    * XXXXX -> w: 5
    * -XXXX -> w: 4
    * --XXX -> w: 3
    * ---XX -> w: 2
    * ----X -> w: 1
    */
   for (int p = c, minH = INT_MAX; p < *matrixColSize; p++) {
    minH = minH > histogramH[p] ? histogramH[p] : minH;
    w = p - c + 1;
    maxArea = maxArea < minH * w ? minH * w : maxArea;
   }
  }
 }

 free(histogramH);
 return maxArea;
}

int main (void) {

 return 0;
}
