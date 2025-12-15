long long getDescentPeriods(int* prices, int pricesSize) {
  long long cnt = 0; 
  long long *stack = (long long*) malloc(pricesSize * sizeof(long long));
  int top = -1;
  int smoothDes = 1;

  // counting as long as possible
  for (int i = 0; i < pricesSize-1; i++) {
    if (prices[i] - 1 == prices[i+1]) {
      smoothDes++;
    } else {
      stack[++top] = smoothDes;
      smoothDes = 1;
    }
  }

  stack[++top] = smoothDes; // the last one

  // summation
  while (top >= 0) {
    for (int i = 1; i <= stack[top]; i++) {
      cnt = cnt + i;
    }
    top--;
  }
  
  free(stack);
         
  return cnt;

}
