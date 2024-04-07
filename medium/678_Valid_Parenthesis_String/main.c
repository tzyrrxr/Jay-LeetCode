#include <stdio.h>

/*
 * We can think three characters '(', ')', and '*' as the weighted.
 * And the sum of the weighted will be the range because '*' can be as increased, decreased, or null.
 * '(': +1 
 * ')': -1 // The smallest value of lower bound is 0.
 * '*': +1, -1, 0
 * The final value will be the range.
 * If the value of lower bound is 0, then it is valid parenthesis string.
 */
bool checkValidString(char* s) {
 int lowerBound = 0, higherBound = 0;
 unsigned int i = 0;

 while (s[i]) {
  if (s[i] == '(') {
   higherBound++;
   lowerBound++;
  } else if (s[i] == ')'){
   higherBound--;
   if (--lowerBound < 0) lowerBound = 0;
  } else if (s[i] == '*') { // increased higher bound, decrease lower bound.
   higherBound++;
   if (--lowerBound < 0) lowerBound = 0;
  }

  // too many ')'
  if (higherBound < 0) return false;

  i++;
 }

 // The smallest value of lower bound is 0. 
 // if too many '(', return false.
 return lowerBound == 0;
}

int main (void) {

 return 0;
}
