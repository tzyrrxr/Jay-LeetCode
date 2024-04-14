#include <stdio.h>

int lengthOfLastWord(char* s) {
 int ret = 0;
 int lS = strlen(s)-1;
 int i;

 // remove the space.
 for (i = lS; s[i] == ' '; i--);

 for (; i >= 0; i--) {
  if (s[i] == ' ') break;
  ret++;
 }

 return ret;
}

int main (void) {

 return 0;
}
