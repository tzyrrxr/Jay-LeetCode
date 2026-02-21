void isPrime (bool *a, int size){

  for (int i = 2; i < size; i++) {
    a[i] = true;
    for (int j = 2; j < i; j++) {
      if ((i % j) == 0) {
        a[i] = false;
        break;
      }
    }
  }

}

int countPrimeSetBits(int left, int right) {
  bool *prime = (bool*) malloc(32*sizeof(bool)+1);
  prime[0] = false;
  prime[1] = false;
  prime[2] = true;
  isPrime (prime, 32*sizeof(bool)+1);
  int cnt = 0;

  for (int i = left; i <= right; i++) {
    int bitCnt = 0;
    int tmp = i;
    while (tmp) {
      bitCnt += tmp & 1;
      tmp >>= 1;
    }
    if (prime[bitCnt] == true) {
      cnt++;
    }
  }

  free(prime);
    
  return cnt;
}
