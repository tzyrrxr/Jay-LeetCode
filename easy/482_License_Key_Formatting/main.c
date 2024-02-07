#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* licenseKeyFormatting(char* s, int k);

int main() {
 //char *s = "5F3Z-2e-9-w";
 //char *s = "2-5g-3-J";
 char *s = "2-4A0r7-4k";

 char *r = licenseKeyFormatting (s, 3);

 printf("Return: %s\n", r);

 return 0;
}

char* licenseKeyFormatting(char* s, int k) {

 // the worst case: a-b-c-d-e-f-...
 char *ret = (char *) malloc (strlen(s) * 2 * sizeof(char));
 int group = 0;
 int i, j;
 char tmp;
 memset (ret, '\0', strlen(s)*2);

 for (i = strlen(s) -1, j = 0 ; i > -1 ; i--) {
  if (s[i] == '-') continue;
  if (group == k) {
   ret[j++] = '-';
   group = 0;
  }
  if (s[i] > 0x60 && s[i] < 0x7B) {
   ret[j++] = s[i] - 0x20;
  } else {
   ret[j++] = s[i];
  }
  group++;
 }
 //realloc(ret, strlen(ret)+1);

 // reverse string
 for (i = 0, j = j-1; i < j; i++, j--) {
  tmp = ret[i];
  ret[i] = ret[j];
  ret[j] = tmp;
 }

 return ret;
}
