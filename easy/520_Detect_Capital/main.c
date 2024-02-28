#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define AllCapitals 1
#define AllNotCapitals 2
#define FirstCapital 3

bool detectCapitalUse(char* word) {
  int type = 0;

  if (strlen(word) == 1) return true;

  if (strlen(word) <= 2) {
    // lowercase + uppercase
    if (word[0] > 0x60 && word[1] < 0x5B) {
      return false;
    }
    return true;
  }

  // checking type
  if (word[0] > 0x60 && word[1] > 0x60) {
    type = AllNotCapitals;
  } else if (word[0] > 0x40 && word[1] > 0x60) {
    type = FirstCapital;
  } else if (word[0] < 0x5B && word[1] < 0x5B){
    type = AllCapitals;
  } else {
    return false;
  }


  switch (type) {

    case AllCapitals:
      for (int i = 2; i < strlen(word); i++) {
        if (word[i] > 0x60) return false;
      }
      break;

    case AllNotCapitals:
    case FirstCapital:
      for (int i = 2; i < strlen(word); i++) {
        if (word[i] < 0x5B) return false;
      }
      break;

    default:
      return false;
      break;
  }

  // all pass
  return true;
}

int main (void) {
  char * s = "mRZ";

  detectCapitalUse(s);

  return 0;
}
