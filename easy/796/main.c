bool rotateString(char* s, char* goal) {
  if (strlen(s) != strlen(goal)) return false;
  int pt = s[0];
  int len = strlen(s);
  bool flag = false;
  for (int i = 0; i < len; i++) {
    if (s[0] == goal[i]) {
      flag = true;
      int j;
      for (j = 0; j < len; j++) {
        if (s[j] != goal[(i+j) % len]) {
          flag = false;
          break;
        }
      }
      if (j == len) return flag;
    }
  }

  return flag;
}
