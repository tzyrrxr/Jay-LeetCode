int countBinarySubstrings(char* s) {
  char *pt = s;
  int len = strlen(s);
  int res = 0;

  for (int i = 1, curr = 1, pre = 0; i < len; i++) {
    if (!(s[i] - s[i-1])) {
      curr++;
    } else {
      pre = curr;
      curr = 1;
    }
    if (pre >= curr) {
      res++;
    }

  }
    
  return res;
}
