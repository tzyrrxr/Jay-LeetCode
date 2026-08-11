bool hasAllCodes(char* s, int k) {
  // there are 2^k possiable solutions.
  int possible = 1 << k;
  bool hash[possible];
  int len = strlen(s);
  int val = 0;

  memset(hash, 0, sizeof(hash));

  for (int i = 0, tmp = possible; i < len; i++) {
    val = ((val << 1) & ~tmp) + s[i] - '0';
    if (i+1 >= k && hash[val] == false) {
      hash[val] = true;
      possible--;
      if (possible == 0) return true;
    }
  }
    
  return false;

}
