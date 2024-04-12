#include <stdio.h>

// stack to index of height
int trap(int* height, int heightSize) {
 int top = -1;
 int indexStack[heightSize];
 int sum = 0;

 int r, l, d, w, h; // right, left, down of bowl, width, height

 // pointer to right side index
 for (int r = 0; r < heightSize; r++) {

  // sum of capacity
  while (top >= 0 && // left side index is into stack
         height[r] > height[indexStack[top]]
    ) {
   d = indexStack[top];
   if (--top == -1) break;; // stack is empty
   
   l = indexStack[top]; // determine left side.
   h = height[r] < height[l] ? height[r] : height[l];
   h -= height[d];
   w = r - l -1;

   sum += h*w; // sum of capacity
  }

  indexStack[++top] = r;
 }
    
 return sum;
}

int main (void) {

 return 0;
}
