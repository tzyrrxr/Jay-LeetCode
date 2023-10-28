#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool compare2Str(char* str1, char* str2) {
 unsigned int len = strlen(str1);
 while(len--) {
  if (str1[len] != str2[len]) {
   //printf("not match: len %d, str1: %c, str2: %c\n", len, str1[len], str2[len]);
   return 0;
  }
 }
 return 1;
}

char* copyStr(char* s, unsigned int len, unsigned int n) {
 char *ret = (char *)malloc(len*n+1);
 unsigned int needle = 0;
 ret[len*n] = '\0';

 // debug
 //for(int i=0; i<len; i++)
 //printf("%c", s[i]);
 //printf("\n");

 for (unsigned int i = 0; i<len*n; i++) {
  if (needle == len) needle = 0;
  ret[i] = s[needle];
  needle++;
 }

 //printf("ret len: %s\n", ret);
 
 return ret;
}

bool repeatedSubstringPattern(char * s){
 unsigned int len = strlen(s);
 char *checkStr;
 bool checker = 0;

 for (unsigned int i = 1; i <= len/2; i++) {
  //printf("i: %d\n", i);
  if (len%i == 0) {
   checkStr = copyStr(s, i, len/i);
   checker = compare2Str(s, checkStr);

   //printf("str1: %s, str2: %s, return: %d\n", s, checkStr, checker);

   free(checkStr);
   if (checker) return checker;
  }
 }

 //printf("finish: %d\n", checker);
 //free(checkStr);

 return checker;
}



int main () {
 int ret;
 char *s = "abaababaab";

 printf("strlen: %lld\n", strlen(s));
 ret = repeatedSubstringPattern(s);

 if (ret) printf("YES\n");
 else printf("NO\n");

 return 0;
}
