int CMP (const void *a, const void *b) {
  return *(int*) a - *(int*) b;
}

int maxIceCream(int* costs, int costsSize, int coins) {
  qsort(costs, costsSize, sizeof(int), CMP);

  int cnt = 0;
  int i = 0;
  for (int i = 0; i < costsSize; i++) {
    if (coins - costs[i] >= 0) {
      coins -= costs[i];
      cnt++;
    } else {
      break;
    }
  }
    
  return cnt;
}
