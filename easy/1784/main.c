bool checkOnesSegment(char* s) {
  while (*s == '1' && *s != '\0') {
    s++;
  }
  while (*s == '0' && *s != '\0') {
    s++;
  }
    
  return *s == '\0';
}
