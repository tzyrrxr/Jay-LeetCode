#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* licenseKeyFormatting(char* s, int k);

int main() {
 char *s = "5F3Z-2e-9-w";

 char *r = licenseKeyFormatting (s, 4);

 printf("Return: %s\n", r);

 return 0;
}

char* licenseKeyFormatting(char* s, int k) {
 //if (s[0] == '-') return s;
 //char ret[(10^5)+1] = {'\0'}; 
 char *ret = (char *) malloc(sizeof(char)*((10^5)+1));
 unsigned int retIndex = 0;
 int  gMember = 0;
 int firstGroupChecker = 0;

 // initialize ret '\0'
 memset (ret, '\0', (10^5)+1);

 for (int i = 0; s[i] != '\0'; i++) {

  //if (s[i] == '-') continue;

  // convert lowercases to uppercase
  // a ~ z
  // ASCii: 0x61 ~ 0x7A
  if (s[i] - 0x7B < 0) {
   s[i] = s[i] - 0x20;
  }

  // put the char into array
  if (gMember < k && firstGroupChecker == 0) {
   ret[retIndex++] = s[i];
   gMember++;
  } else {
   ret[retIndex++] = '-';
   gMember = 0;
  }




  // put the character into array.

  //// A ~ Z
  //// ASCii: 0x41 ~ 0x5A
  //if (s[i] - 0x5B < 0) {
  // continue;
  //}

  // Dash
  // ASCii: 0x2D




 }
 return ret;
}
