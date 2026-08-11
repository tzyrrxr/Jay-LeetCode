#define MOD 1000000007

int concatenatedBinary(int n){
  long long res = 0;

  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    int tmp = i;
    while (tmp) {
      cnt++;
      tmp >>= 1;
    }

    res = ((res << cnt) + i) % MOD;
  }

  return (int) res;

}
