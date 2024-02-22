#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

char* convertToBase7(int num) {
 int base7 = 0;
 int i;
 char *ret;
 int len;

 for (i = 1, len = 1; num; num/=7, i *= 10, len++) {
  base7 = base7 + (num % 7) * i;
 }
 ret = (char*) calloc('\0', sizeof(char) * len);

 itoa(base7, ret, 7);
 return ret;
}

int main (void) {
 char *s = convertToBase7 (100);

 printf("string: %s\n", s);

 return 0;
}
