#include <stdio.h>

int trib[38] = {0};

int tribonacci(int n){
 if (n == 0) return 0;
 else if (n == 1 || n == 2) return 1;
 else if (trib[n] == 0) trib[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);

 return trib[n];
}

int main (void) {

 return 0;
}
