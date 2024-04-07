#include <stdio.h>
#include <stdlib.h>

char* makeGood(char* s) {
 if (strlen(s) <= 1) return s;
 char *ret = (char *) malloc(101);
 int retIndex = -1;
 int len = strlen(s);


 for (int i = 0; i < len; i++) {
  if (retIndex != -1 && (ret[retIndex] - s[i] == 0x20 || ret[retIndex] - s[i] == -0x20)) {
   retIndex--;
  } else {
   ret[++retIndex] = s[i];
  }
 }
 ret[++retIndex] = '\0';

 return ret;
}

int main (void) {

 return 0;
}
