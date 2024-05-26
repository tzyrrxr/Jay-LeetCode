#include <stdio.h>

struct h_letters {
 char key;
 char *s;
 UT_hash_handle hh;
};

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
 int len = strlen(digits);
 if (!len) {
  *returnSize = 0;
  return NULL;
 }

 struct h_letters l2 = {'2', "abc"};
 struct h_letters l3 = {'3', "def"};
 struct h_letters l4 = {'4', "ghi"};
 struct h_letters l5 = {'5', "jkl"};
 struct h_letters l6 = {'6', "mno"};
 struct h_letters l7 = {'7', "pqrs"};
 struct h_letters l8 = {'8', "tuv"};
 struct h_letters l9 = {'9', "wxyz"};
 struct h_letters *h_head = NULL;

 char **ret;
 int index = 0;

 BT (index, digits, ret, returnSize);
    
 return ret;
}

int main (void) {
 
 return 0;
}
