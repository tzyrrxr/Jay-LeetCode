#include <stdio.h>

char* reversePrefix(char* word, char ch) {

 for (int i = 0; word[i] != '\0'; i++) {

  if (word[i] == ch) {
   int j = 0;
   int z = i;
   char tmp;
   for (; j < z; j++, z--) {
    tmp = word[j];
    word[j] = word[z];
    word[z] = tmp;
   }
   break;
  }
 }

 return word;
}

int main (void) {

 return 0;
}
