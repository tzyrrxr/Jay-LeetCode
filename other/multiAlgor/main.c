#include <stdio.h>

int mul (int a, int b) {

 int shift = 0;
 int ret = 0;

 while (b) {
  if (b % 2 == 1) {
   ret += a << shift;
  }
  shift++;
  b >>= 1;
 }

 printf("%d\n", ret);
}

int main () {
 mul (5, 100);
 return 0;
}
