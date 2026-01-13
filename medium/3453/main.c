#include <limits.h>
#include <math.h>

#define PERCISION 0.00001

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
  double totalArea = 0;
  double height = INT_MIN;
  double low = 0.0;
  double ansY;

  for (int i = 0; i < squaresSize; i++) {
    totalArea += (double)squares[i][2] * (double)squares[i][2];
    height = fmax(height, squares[i][1] + squares[i][2]);
  }

  while (height - low > PERCISION) {
    ansY = (height + low) / 2.0;
    double aboveArea = 0.0;
    for (int i = 0; i < squaresSize; i++) {
      if (squares[i][1] > ansY) {
        aboveArea += (double)squares[i][2] * (double)squares[i][2];
      } else if (squares[i][1] + squares[i][2] > ansY) {
        aboveArea += (double)(squares[i][1] + squares[i][2] - ansY) * (double)squares[i][2];
      }
    }
    // If aboveArea is more than half of totalArea, we need to increase low bound.
    // The division is more cycle efficient than multiplying.
    if (aboveArea * 2 > totalArea) {
      low = ansY;
    } else {
      height = ansY;
    }
  }

  return ansY;
    
}
