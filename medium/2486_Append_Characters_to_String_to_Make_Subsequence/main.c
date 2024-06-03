#include <stdio.h>

int appendCharacters(char* s, char* t) {
  int slen = strlen(s);
  int tlen = strlen(t);
  int pt = 0;

  for (int i = 0; i < slen && pt < tlen; i++) {
    if (s[i] == t[pt]) pt++;
  }
    
  return tlen - pt;

}

int main (void) {
 
 return 0;
}
