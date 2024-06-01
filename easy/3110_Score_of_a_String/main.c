#include <stdio.h>

int scoreOfString(char* s) {
 int sum = 0;
 int val; 
 int pt = 1;

 while (s[pt]) {

  val = s[pt-1] - s[pt];
  if (val < 0) val = ~val + 0x1;
  sum += val;

  pt++;
 }

 return sum;

}

int main (void) {
 
 return 0;
}
