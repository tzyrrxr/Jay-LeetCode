#include <stdio.h>

bool hasAlternatingBits(int n) {
 bool probe = n & 0x1;
 for (; n; probe = !probe, n >>= 1) {
  if (probe != (bool)(n & 0x1)) return false;
 }

 return true;
}

int main (void) {

 return 0;
}
