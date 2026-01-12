// You have to visit the points in the same order as they appear in the array.
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
  int time = 0;
  int **p = points;

  for (int i = 1; i < pointsSize; i++) {
    int dx = p[i][0] - p[i-1][0];
    dx = (dx >> 31) ? -dx : dx;
    int dy = p[i][1] - p[i-1][1];
    dy = (dy >> 31) ? -dy : dy;
    time += (dx > dy) ? dx : dy;
  }
    
  return time;

}
