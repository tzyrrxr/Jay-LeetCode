int minPartitions(char* n) {
  int max = 0;

  while (*n != '\0') {
    if (*n == '9') {
      return 9;
    }
    if (*n - '0' > max) {
      max = *n - '0';
    }
    n++;
  }

  return max;
    
}
