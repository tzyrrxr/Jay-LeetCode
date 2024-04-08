#include <stdio.h>

bool verifyPreorder(int* preorder, int preorderSize) {
 int prev = INT_MIN;
 int stack[10000] = {0};
 int top = -1;

 for (int i = 0; i < preorderSize; i++) {
  if (preorder[i] < prev) return false; // number should be bigger than previous one.

  // Remove the compared values.
  while (top != -1 && preorder[i] > stack[top]) {
   prev = stack[top--];
  }

  stack[++top] = preorder[i];
 }

 return true;
    
}

int main (void) {

 return 0;
}
