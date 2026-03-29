bool canBeEqual(char* s1, char* s2) {
  int len = strlen(s1);

  for (int i = 0; i < len-2; i++) {
    if (!((s1[i]^s2[i]) == 0 || (s1[i]^s2[i+2]) == 0) || !((s1[i+2]^s2[i]) == 0 || (s1[i+2]^s2[i+2]) == 0)) return false;
  }

  return true;
    
}
