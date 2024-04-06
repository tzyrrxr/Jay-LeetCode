#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* minRemoveToMakeValid(char* s) {
 int tmp = 0;
 unsigned int n = strlen(s);
 unsigned int str1Size = 0;
 unsigned int str2Size = 0;
 // If str1's and str2's address are too close to input the character into str1.
 char *str1 = (char*) malloc(100000 * sizeof(char));
 char *str2 = (char*) malloc(100000 * sizeof(char));

 // Remove '('
 for (int i = n-1; i >= 0; i--) {
  /* 
   * '(' -> +1
   * ')' -> -1
   */
  tmp += ( (s[i] == '(') - (s[i] == ')') );

  if (tmp <= 0) {
   //str1 = realloc(str1, (str1Size + 1) * sizeof(char));
   str1[str1Size++] = s[i];
  } else {
   tmp = 0; // reset
  }
 }

 // Remove ')'
 for (int i = str1Size - 1, tmp = 0; i >= 0; i--) {
  /* 
   * '(' -> +1
   * ')' -> -1
   */
  tmp += ( (str1[i] == '(') - (str1[i] == ')') );

  if (tmp >= 0) {
   //str2 = realloc(str2, (str2Size + 1) * sizeof(char));
   str2[str2Size++] = str1[i];
  } else {
   tmp = 0;
  }
 }

 str2 = realloc(str2, (str2Size + 1) * sizeof(char));
 str2[str2Size] = '\0';

 free(str1);

 return str2;
}

int main (void) {
 char *s = "lee(t(c)o)de)";
 char *ret = minRemoveToMakeValid (s);

 printf("result: %s\n", ret);

 return 0;
}
