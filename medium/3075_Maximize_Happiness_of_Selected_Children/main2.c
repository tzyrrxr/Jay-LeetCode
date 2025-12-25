int CMP (const void *a, const void *b) {
  return *(int*)b - *(int*)a;
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
  long long max = 0;

  qsort (happiness, happinessSize, sizeof(int), CMP);

  for (int i = 0, turn = 0, val = 0; 
    i < k && 0 < (val = happiness[i]-turn); // Index i is alwasy less than k. happiness[i]-turn is first assign to val, then val is compared to 0.  
    i++, turn++) {
    max += (long long)val;
  }
    
  return max;

}
