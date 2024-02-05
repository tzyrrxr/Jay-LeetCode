#include <stdio.h>

void base_expansion (int base, int val) {
 int dir = val;
 int rem = 0;
 while (dir) {
  printf("%d ", dir%base);
  dir /= base;
 }

}

int main () {
 int val = 12345;
 base_expansion (8, val);

 return 0;
}
