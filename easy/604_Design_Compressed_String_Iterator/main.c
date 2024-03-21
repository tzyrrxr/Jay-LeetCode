#include <stdio.h>

/**
 * INPUT: 
 * ["StringIterator", "next", "next", "next", "next", "next", "next", "hasNext", "next", "hasNext"]
 * [["L1e2t1C1o1d1e1"], [], [], [], [], [], [], [], [], []]
 *
 * OUTPUT:
 * [null, "L", "e", "e", "t", "C", "o", true, "d", true]
 *
 *
*/

typedef struct {
 char *inputStr; 
 int strIndex;

 char probeChar;
 int  probeCharCount;
 
} StringIterator;


StringIterator* stringIteratorCreate(char* compressedString) {
 StringIterator *ret = (StringIterator *) malloc (sizeof(StringIterator));

 ret->inputStr = compressedString;
 ret->strIndex = 0;

 ret->probeChar = ' ';
 ret->probeCharCount = 0;

 return ret;
}

bool stringIteratorHasNext(StringIterator* obj) {
 return obj->strIndex < strlen(obj->inputStr) || obj->probeCharCount > 0;
}

char stringIteratorNext(StringIterator* obj) {
 if (!stringIteratorHasNext(obj)) return ' ';


 if (obj->probeCharCount == 0) {

  obj->probeChar = obj->inputStr[obj->strIndex++];

  int digitNum = 0;
  while (obj->strIndex < strlen(obj->inputStr) && isdigit(obj->inputStr[obj->strIndex])) {
   digitNum *= 10;
   digitNum += obj->inputStr[obj->strIndex] - '0';
   obj->strIndex++;
  }

  obj->probeCharCount = digitNum;
 }

 obj->probeCharCount--;

 return obj->probeChar;
}


void stringIteratorFree(StringIterator* obj) {
 free(obj);
}

/**
 * Your StringIterator struct will be instantiated and called as such:
 * StringIterator* obj = stringIteratorCreate(compressedString);
 * char param_1 = stringIteratorNext(obj);
 
 * bool param_2 = stringIteratorHasNext(obj);
 
 * stringIteratorFree(obj);
*/

int main (void) {

 return 0;
}
