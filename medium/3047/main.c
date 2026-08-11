long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize, int** topRight, int topRightSize, int* topRightColSize) {
  int side = 0;
  int count = 0;
  int PossibleCount = (bottomLeftSize * (bottomLeftSize - 1)) / 2; // Possible count = nC2


  // Get intervals as possible
  for (int i = 0; i < bottomLeftSize; i++) {
    int xStart1 = bottomLeft[i][0];
    int yStart1 = bottomLeft[i][1];
    int xEnd1 = topRight[i][0];
    int yEnd1 = topRight[i][1];
    for (int j = i + 1; j < bottomLeftSize; j++) {
      int xStart2 = bottomLeft[j][0];
      int yStart2 = bottomLeft[j][1];
      int xEnd2 = topRight[j][0];
      int yEnd2 = topRight[j][1];

      int w = 0;
      int wStart, wEnd;
      int h = 0;
      int hStart, hEnd;

      // Calculate width
      wStart = (xStart1 > xStart2) ? xStart1 : xStart2;
      wEnd = (xEnd2 > xEnd1) ? xEnd1 : xEnd2;
      w = wEnd - wStart;
      if (w < 0) continue;

      // Calculate height
      hStart = (yStart1 > yStart2) ? yStart1 : yStart2;
      hEnd = (yEnd2 > yEnd1) ? yEnd1 : yEnd2;
      h = hEnd - hStart;
      if (h > 0) {
        side = fmax(side, fmin(w, h));
      }


      
    }

  }

  return (long long)side * side;
    
}
