int CMP (const void *a, const void *b) {
  return *(int*)b - *(int*)a;
}
int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
  int min = 0;
  int total = 0;

  qsort(capacity, capacitySize, sizeof(int), CMP);
  for (int i = 0; i < appleSize; i++) total += apple[i];
  for (int i = 0; i < capacitySize && total > 0; i++) {
    total -= capacity[i];
    min++;
  }

  return min;
    
}
