#include <stdio.h>

char* reverseStr(char* s, int k) {
  if (strlen(s) <= 1) return s;
  int skip = 0;
  int probe = 0;
  int left, right;

  while (probe < strlen(s)) {

    if (!skip) {
      if (probe + k >= strlen(s)) {
        k = strlen(s) - probe;
      }

      char tmp;
      for (left = probe, right = probe + k -1; left <= right; left++, right--) {
        tmp = s[right];
        s[right] = s[left];
        s[left] = tmp;
      }
    } 

    skip = !skip;
    probe += k;

  }

  return s;
}

int main (void) {

 return 0;
}
