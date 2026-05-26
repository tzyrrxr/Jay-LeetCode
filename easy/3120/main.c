int numberOfSpecialChars(char* word) {
  int ret = 0;
  bool *hash = (bool*) calloc(128, sizeof(bool));

  for (int i = 0; word[i] != '\0'; i++) {
    hash[word[i]] = 1;
  }
  for (int i = 'a'; i <= 'z'; i++) {
    if (hash[i] && hash[i - 'a' + 'A']) ret++;
  }
    
  free(hash);
  return ret;
}
