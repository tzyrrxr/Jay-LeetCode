#include <stdio.h>

bool compareString (char *a, char *b) {
 if (strlen(a) != strlen(b)) return false;

 for (int i = 0; i < strlen(a); i++) {
  if (a[i] != b[i]) return false;
 }

 return true;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {

 char **retArr;
 int minIndex = INT_MAX;
 // malloc 
 if (list1Size > list2Size) {
  retArr = (char**) malloc(list1Size * sizeof(char*));
 } else {
  retArr = (char**) malloc(list2Size * sizeof(char*));
 }

 *returnSize = 0;
 for (int i = 0; i < list1Size; i++) {
  for (int j = 0; j < list2Size; j++) {
   if (compareString(list1[i], list2[j])) {

     if (minIndex == i+j) {
      retArr[*returnSize] = list1[i];
      (*returnSize)++;
     } else if (minIndex > i+j) {
      minIndex = i + j;
      *returnSize = 0;
      retArr[*returnSize] = list1[i];
      (*returnSize)++;
     }

   }
  }
 }

 return retArr;
}

int main (void) {

 return 0;
}
