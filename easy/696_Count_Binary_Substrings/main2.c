int countBinarySubstrings(char* s) {
  char *pt = s;
  int len = strlen(s);
  int *subCnt = (int*) malloc(len*sizeof(int));
  int top = 0;
  int cnt = 1;
  int res = 0;

  subCnt[top] = cnt;

  for (int i = 1; i < len; i++) {
    switch (s[i] - s[i-1]) {
      case -1:
      case 1 :
        cnt = 1;
        subCnt[++top] = cnt;
        break;

      case 0:
      default:
        subCnt[top] = ++cnt;
        break;
    }
  }

  for (int i = 1; i <= top; i++) {
    res += fmin(subCnt[i], subCnt[i-1]);
  }
    
  return res;
}
