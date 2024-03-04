#include <stdio.h>

char* reverseWords(char* s) {
  int start, end;

  for (start = 0, end = 0; end < strlen(s) + 1; end++) {
    if (s[end] == ' ' || s[end] == '\0') {
      int l, r, tmp;
      for (l = start, r = end - 1; l < r; l++, r--) {
        tmp = s[r];
        s[r] = s[l];
        s[l] = tmp;
      }
      start = end + 1;
    }
  }

  return s;
}

int main (void) {

  return 0;
}
