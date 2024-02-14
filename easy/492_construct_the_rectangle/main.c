#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
 int r = 1;
 int l = area;

 returnSize[0] = l;
 returnSize[1] = r;
 for (; r <= l; r++) {

  if (area % r == 0) {

   l = area / r;
   if (l >= r) {
    returnSize[0] = l;
    returnSize[1] = r;
   } else {
    break;
   }

  }

 }

 return returnSize;
}

// 
// By function sqrt(); 
//
// #include <math.h>
// 
// int* constructRectangle(int area, int* returnSize) {
//  int r = sqrt(area);
//  *returnSize = 2;
//  int *ret = (int *) malloc(*returnSize * sizeof(int));
// 
//  while(area % r) r--;
//  ret[0] = area / r;
//  ret[1] = r;
// 
//  return ret;
// }

int main (int argc, char *argv[]) {
 int *returnSize = (int *) malloc( 2 * sizeof(int));
 constructRectangle (122122, returnSize);
 printf("first: %d, second: %d\n", returnSize[0], returnSize[1]);

 free(returnSize);

 return 0;
}
