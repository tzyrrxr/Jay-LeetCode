#include <stdio.h>

// *. Go through the all of the digital value and put the digit character into the stack.
// 1. First to remove the digital of higher value if it find the small one by greedy algorithm.
// 2. If it has the value to remove(k != 0), then remove the top of stack. (No value is higher after digital character)
char* removeKdigits(char* num, int k) {
 int top = -1;
 int len = strlen(num);
 char *stack = (char*) malloc(len * sizeof(char));
 char *ret;

 for (int i = 0; i < len; i++) {
  while (k > 0 && top >= 0 && stack[top] > num[i]) {
   top--;
   k--;
  }
  stack[++top] = num[i];
 }

 // No value is higher after digital character
 while (k > 0) {
  top--;
  k--;
 }
 // no value
 if (top == -1) return "0";

 stack[++top] = '\0';

 // Remove zero digit from the left.
 for (int i = 0; i < top; i++) {
  if (stack[i] == '0') continue;
  ret = stack + i;
  break;
 }
 
 return ret;
}

int main (void) {

 return 0;
}
