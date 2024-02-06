#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* licenseKeyFormatting(char* s, int k);

int main() {
 char *s = "5F3Z-2e-9-w";
 //char *s = "2-5g-3-J";

 char *r = licenseKeyFormatting (s, 2);

 printf("Return: %s\n", r);

 return 0;
}

char* licenseKeyFormatting(char* s, int k) {
 //if (s[0] == '-') return s;
 //char ret[(10^5)+1] = {'\0'}; 
 char *ret = (char *) malloc(sizeof(char)*((10^5)+1));
 unsigned int retIndex = 0;
 int  gMember = 0;
 int i = 0;
 

 // initialize ret '\0'
 memset (ret, '\0', (10^5)+1);

 // first group
 for (i = 0; s[i] != '-' && gMember < k; i++) {
   // convert lowercases to uppercase
   // a ~ z
   // ASCii: 0x61 ~ 0x7A
   if (s[i] < 0x7B && s[i] > 0x60) {
    ret[retIndex++] = s[i] - 0x20;
   } else {
    ret[retIndex++] = s[i];
   }
   gMember++;
 }
 ret[retIndex++] = '-';
 gMember = 0;

 for (; s[i] != '\0'; i++) {

  // skip '-'
  if (s[i] == '-') continue;

  // put the char into array
  if (gMember < k) {
   // convert lowercases to uppercase
   // a ~ z
   // ASCii: 0x61 ~ 0x7A
   if (s[i] < 0x7B && s[i] > 0x60) {
    ret[retIndex++] = s[i] - 0x20;
   } else {
    ret[retIndex++] = s[i];
   }
   gMember++;
  } else {
   ret[retIndex++] = '-';
   // convert lowercases to uppercase
   // a ~ z
   // ASCii: 0x61 ~ 0x7A
   if (s[i] < 0x7B && s[i] > 0x60) {
    ret[retIndex++] = s[i] -0x20;
   } else {
    ret[retIndex++] = s[i];
   }
   gMember = 0;
  }

 }

 return ret;
}
