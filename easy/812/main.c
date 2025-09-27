#include <stdio.h>
#include <math.h>

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
  double maxArea = 0;
  double area = 0;

  for (int i = 0; i < pointsSize-2; i++) {
    for (int j = i+1; j < pointsSize-1; j++) {
      for (int k = j+1; k < pointsSize; k++) {
        int x1 = points[i][0];
        int y1 = points[i][1];

        int x2 = points[j][0];
        int y2 = points[j][1];

        int x3 = points[k][0];
        int y3 = points[k][1];

        /*
         * |   x     y     z |
         * | x2-x1 y2-y1   0 |
         * | x3-x1 y3-y1   0 |
        */

        area = 0.5 * fabs(
                 (x2-x1) * (y3-y1) -
                 (x3-x1) * (y2-y1)
                 );

        if (area > maxArea) {
          maxArea = area;
        }
      }
    }
  }
  
  return maxArea;
    
}

int main () {

  return 0;
}
