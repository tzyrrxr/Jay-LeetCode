int Max (int a, int b) {
  return a > b ? a : b;
}
int CMP (const void *a, const void *b) {
  int *StartA = *(int**)a;
  int *StartB = *(int**)b;
  if (StartA[0] != StartB[0]) {
    return StartA[0] - StartB[0];
  }

  return StartA[1] - StartB[1];
}


int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {
    int max = 0;
    int **greedy = malloc(eventsSize*2*sizeof(int*));

    // greedy[i] = {time, flag, value}
    // flag 0: start time, 
    // flag 1: end time
    for (int i = 0; i < eventsSize; i++) {
       // store start time, flag, and value
       greedy[i*2] = (int*)malloc(3*sizeof(int));
       greedy[i*2][0] = events[i][0];
       greedy[i*2][1] = 0;
       greedy[i*2][2] = events[i][2];

       // store end time, flag, and value
       greedy[i*2+1] = (int*)malloc(3*sizeof(int));
       greedy[i*2+1][0] = events[i][1];
       greedy[i*2+1][1] = 1;
       greedy[i*2+1][2] = events[i][2]; // maybe its value is bigger when we haven't it on start time.
    }

    qsort(greedy, eventsSize*2, sizeof(int*), CMP);

    for (int i = 0, best = 0; i < eventsSize*2; i++) {
      if (greedy[i][1] == 0) { // start time
        max = Max(max, best + greedy[i][2]);
      } else { // end time
        best = Max(best, greedy[i][2]);
      }
    }

    return max;
}
