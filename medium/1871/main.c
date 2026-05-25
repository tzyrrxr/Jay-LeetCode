bool canReach(char* s, int minJump, int maxJump) {
  int len = strlen(s);
  if (s[len-1] == '1') return false;
  bool ret;
  bool *reach = (bool*) calloc(len, sizeof(bool));
  int *ReachCnt = (int*) malloc(len*sizeof(int)); // prefix sum

  for (int i = 0; i < minJump; i++) {
    ReachCnt[i] = 1;
  }

  for (int i = minJump; i < len; i++) {
    // jump range to i position
    int l = i - maxJump;
    int r = i - minJump;
    if ('0' == s[i]) {
      int count = ReachCnt[r];
      if (0 <= l-1) {
        count -= ReachCnt[l-1];
      }
      if (count != 0) {
        reach[i] = true; // The index i can be reach.
      }
    }
    ReachCnt[i] = ReachCnt[i-1] + reach[i]; // The default value of reach[i] is zero.
  }
  ret = (true == reach[len-1]);
  free(reach);
  free(ReachCnt);
    
  return ret;
}
