int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
  int res = 0;
  int **planSums = malloc((matSize + 1) * sizeof(int *));

  for (int i = 0; i <= matSize; i++) {
    planSums[i] = calloc((*matColSize+1), sizeof(int));
  }

  // 2D prefix sum
  for (int i = 1; i <= matSize; i++) {
    for (int j = 1; j <= *matColSize; j++) {
      planSums[i][j] = planSums[i-1][j] + planSums[i][j-1] - planSums[i-1][j-1] + mat[i-1][j-1]; // mat is 0-indexed
    }
  }

  for (int i = 1; i <= matSize; i++) {
    for (int j = 1; j <= *matColSize; j++) {
      int currentSide = res+1;
      if (currentSide <= i && currentSide <= j) {
        int squareSideSum = planSums[i][j] 
                            - planSums[i-currentSide][j] 
                            - planSums[i][j-currentSide] 
                            + planSums[i-currentSide][j-currentSide];
        if (squareSideSum <= threshold) {
          res++;
        }
      }
    }
  }
  free(planSums);
    
  return res;
}
