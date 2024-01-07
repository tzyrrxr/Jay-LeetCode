#include <stdio.h>

int findComplement(int num) {
 unsigned int mask = ~0; // example: 8-bit -> ~0 == 1111 1111
 // remove the left side 1 for num
 while(mask & num) mask <<= 1;
 return ~num ^ mask;
}

int main (void) {
 printf("result: %d\n", findComplement (5));
 return 0;
}
