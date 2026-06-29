int numOfStrings(char** patterns, int patternsSize, char* word) {
  int cnt = 0;

  for (int i = 0; i < patternsSize; i++) {
    if (strstr(word, patterns[i])) cnt++;
  }

  return cnt;
    
}
