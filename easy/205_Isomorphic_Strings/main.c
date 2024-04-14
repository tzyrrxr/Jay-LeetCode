#include <stdio.h>

// hash table to save the index of character on the string
bool isIsomorphic(char* s, char* t) {
 if (!s || !t) return false;

 int len = strlen(s);
 if (len != strlen(t)) return false;

 int hashS[0x7F] = {0};
 int hashT[0x7F] = {0};

 for (int i = 0; i < len; i++) {
  if (hashS[s[i]] != hashT[t[i]]) return false;

  // avoid initilize zero number, we increase one index.
  hashS[s[i]] = i + 1;
  hashT[t[i]] = i + 1;
 }

 return true;
}

int main (void) {

 return 0;
}
