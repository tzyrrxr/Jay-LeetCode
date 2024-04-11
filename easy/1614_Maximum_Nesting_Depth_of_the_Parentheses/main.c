#include <stdio.h>

int maxDepth(char* s) {
 int max = 0;
 int len = strlen(s);
 int buffer = 0;

 for (int i = 0; i < len; i++) {
  buffer += (s[i] == '(') - (s[i] == ')');
  if (buffer > max) max = buffer;
 }

 return max;
}

int main (void) {

 return 0;
}
