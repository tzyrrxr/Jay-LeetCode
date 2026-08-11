int rotatedDigits(int n) {
  char ch[32] = {0};
  int tmp = n;
  int len = 0;

  do {
    ch[len++] = tmp/10 + '0';
    tmp /= 10;
  } while(tmp);
  ch[len] = '\0';
  for (int i = 0; i < len/2; i++) {
    tmp = ch[i];
    ch[i] = ch[len-1-i];
    ch[len-1-i] = tmp;
  }
  // dp
    
}
