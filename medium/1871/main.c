bool canReach(char* s, int minJump, int maxJump) {
  int len = strlen(s);
  if (s[len-1] == '1') return false;

  bool ret;
  bool *reach = (bool*) calloc(len, sizeof(bool));
  reach[0] = true;

  int count = 0;

  for (int i = 1; i < len; i++) {
    int l = i - maxJump;
    int r = i - minJump;

    // enter
    if (0 <= r && reach[r]) {
      count++;
    }

    // leave
    if (0 <= l-1 && reach[l-1]) {
      count--;
    }

    if(count && '0' == s[i]) {
      reach[i] = true;
    }
  }

  ret = reach[len-1];
  free(reach);
    
  return ret;
}
