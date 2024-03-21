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
    
}

char stringIteratorNext(StringIterator* obj) {
    
}

bool stringIteratorHasNext(StringIterator* obj) {
 return obj->strIndex < strlen(obj->inputStr) || obj->probeCharCount > 0
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
