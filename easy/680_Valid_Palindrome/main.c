#include <stdio.h>

bool simplePalindrome (char *s) {
 int l, r;

 for (l = 0, r = strlen(s)-1; l<=r; l++, r--) {
  if (s[l] != s[r]) return false;
 }

 return true;
}

bool validPalindrome(char* s) {
 bool ret;

 ret = simplePalindrome (s);
 if (!ret) {
  for (int i = 0; i < strlen(s); i++) {
   char *tmp = (char *) calloc (strlen(s) + 1, sizeof(char));
   memcpy(tmp, s, strlen(s));
   for (int j = i; j < strlen(s)-1; j++) {
    tmp[j] = tmp[j+1];
   }
   tmp[strlen(s)-1] = '\0';
   ret = simplePalindrome(tmp);
   free(tmp);
   if (ret) break;
  }
 }

 return ret;
}

int main (void) {

 return 0;
}
