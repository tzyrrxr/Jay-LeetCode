#include <stdio.h>

bool simplePalindrome (char *s, int l, int r) {

 while (l <= r) {
  if (s[l] != s[r]) return false;
  l++; r--;
 }

 return true;
}

bool validPalindrome(char* s) {
 int l, r;

 l = 0;
 r = strlen(s) - 1;

 while (l <= r) {
  if (s[l] != s[r]) {
   return simplePalindrome (s, l+1, r) || simplePalindrome (s, l, r-1);
  }
  l++; r--;
 }

 return true;
}

int main (void) {

 return 0;
}
