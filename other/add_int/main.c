#include <stdio.h>

void add (int a, int b) {
 /*
 int carry = 0;
 int s = 0;
 carry = (a%2 + b%2) / 2;
 s     = (a%2 + b%2) % 2;
 printf("%d ", s);
 a >>= 1;
 b >>= 1;

 while (a || b) {
  carry = ((a)%2 + (b)%2 + carry) / 2;
  s     = ((a/2)%2 + (b/2)%2 + carry) % 2;
  printf("%d ", s);
  if (a) a >>= 1;
  if (b) b >>= 1;
 }
 if (s) printf("%d \n", s);
 else printf("\n");
 */

 int carry = 0;
 //int tmp, s;
 int tmp;
 while (a || b) {
  tmp = (a%2 + b%2 + carry) / 2;
  printf("%d ", a%2 + b%2 + carry - 2*tmp);
  carry = tmp;
  a >>= 1;
  b >>= 1;
 }
 printf("%d \n", carry);
 
}

int main () {
 add(11, 4);
 // 101 + 100
 return 0;
}
