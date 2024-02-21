#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

char* convertToBase7(int num) {
 char* ret = (char*) calloc ('\0', sizeof(char) * INT_MAX);
 bool neg = 0;
 int left, right;
 char tmp;

 if (num < 0) {
  num += 2 * num;
  neg = 1;
 }

 for (int i = 1; num; i++) {
  ret[i] = (char)((num % 7) + 0x30);
  num /= 7;
 }

 for (left = 1, right = strlen(ret); left < right; left++, right--) {
  tmp = ret[left];
  ret[left] = ret[right];
  ret[right] = tmp;
 }

 if (neg) {
  ret[0] = '-';
 } else {
  ret += 1;
 }

 return ret;
}

int main (void) {
 char *s = convertToBase7 (100);

 printf("string: %s\n", s);

 return 0;
}
