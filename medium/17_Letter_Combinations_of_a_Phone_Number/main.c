#include <stdio.h>

void BT (int index, char* s, char* digits, char **ret, int *retSize) {
 if (index == strlen(digits)) {
  (*ret)[++(*retSize)] = (char*) malloc(index, sizeof(char));
  strncpy((*ret)[(*retSize)], s, index);
  (*ret)[(*retSize)][index] = '\0';
  return;
 } 
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
 char **ret;
 int index = 0;

 BT (index, digits, ret, returnSize);
    
 return ret;
}

int main (void) {
 
 return 0;
}
