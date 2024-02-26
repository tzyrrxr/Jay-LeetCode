#include <stdio.h>


bool checkPerfectNumber(int num) {
 int sum = 1;
 if (1 >= num) return false;

 for (int i = 2; i*i <= num; i++) {
  if (num % i == 0) {
   sum += i;
   if (i != num/i) { // skip square root
     sum += num/i;
   }
  }
 }

 return num == sum;
}

int main (void) {

 return 0;
}
