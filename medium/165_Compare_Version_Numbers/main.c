#include <stdio.h>
#include <stdlib.h>

int compareVersion(char* version1, char* version2) {

 while (*version1 || *version2) {
  long long v1 = strtol (version1, &version1, 10);
  long long v2 = strtol (version2, &version2, 10);
  if (v1 < v2) return -1;
  if (v1 > v2) return 1;

  if (*version1) version1++;
  if (*version2) version2++;
 }

 return 0;

}

int main (void) {
 char *str = "123.456.789";
 while (*str) {
  printf("%ld\n", strtol(str, &str, 10));
  printf("%c\n", *str);

  puts("Done");
  if (*str) str++;
 }

 // OUTPUT:
 //  123
 //  .
 //  Done
 //  456
 //  .
 //  Done
 //  789
 //  
 //  Done

 return 0;
}
