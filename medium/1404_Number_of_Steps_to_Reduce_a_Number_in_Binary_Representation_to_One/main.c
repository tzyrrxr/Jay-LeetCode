#include <stdio.h>

int numSteps(char* s) {
 int steps = 0;
 int carry = 0;
 int len = strlen(s);

 // s[0] is already 1.
 for (int i = len - 1; i > 0; i--) {
  if ((s[i] - '0' + carry) % 2 == 0) {
   steps++;
  } else {
   carry  = 1; // this carry add into s[i]. Hence, s[i] is 0 and pass 1 to next left bit
   steps += 2;
  }
 }

 // s[0] = 1
 // s[0] + carry == '10'
 // div 2
 if (carry) steps++;

 return steps;
}

int main (void) {
 
 return 0;
}
