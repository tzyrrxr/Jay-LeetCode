#include <stdio.h>



int fib(int n){

  if (n >= 2) {
    return fib(n-1) + fib(n-2);
  } else if (n < 0) {
    return 0;
  }

  return n;
}

int main (void) {

 return 0;
}
