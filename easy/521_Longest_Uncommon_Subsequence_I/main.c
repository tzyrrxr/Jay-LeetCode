#include <stdio.h>

int findLUSlength(char* a, char* b) {

  if (strlen(a) == strlen(b)) {
    int i;
    for (i = 0; i < strlen(a); i++) {
      if (a[i] != b[i]) break;
    }

    if (i == strlen(a)) return -1;
  }

  return strlen(a) > strlen(b) ? strlen(a) : strlen(b);
}


int main (void) {

 return 0;
}
