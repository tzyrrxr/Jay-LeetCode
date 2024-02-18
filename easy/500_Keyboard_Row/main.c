#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int checkRow (char c) {

 int row = 0;
 char uppercase = c;
 if (0x60 < c) uppercase = c - 0x20;

 // which row
 switch (uppercase) {
  // row 1
  case 'Q':
  case 'W':
  case 'E':
  case 'R':
  case 'T':
  case 'Y':
  case 'U':
  case 'I':
  case 'O':
  case 'P':
   row  = 1;
   break;
       
       
  // row 2
  case 'A':
  case 'S':
  case 'D':
  case 'F':
  case 'G':
  case 'H':
  case 'J':
  case 'K':
  case 'L':
   row  = 2;
   break;
       
  // row 3
  case 'Z':
  case 'X':
  case 'C':
  case 'V':
  case 'B':
  case 'N':
  case 'M':
   row = 3;
   break;

  default:
   printf("file: %s, function: %s, line: %d\n", __FILE__, __FUNCTION__, __LINE__);
   break;
 }

 return row;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
 char **ret;
 int row = 0;

 *returnSize = 0;
 ret = (char**) malloc(wordsSize * sizeof(char*));

 for (int i = 0; i < wordsSize; i++) {

  row = checkRow (words[i][0]);
  bool cancelFlag = 0;

  for (int j = 1; j < strlen(words[i]); j++) {
   if (checkRow(words[i][j]) != row) {
    cancelFlag = 1;
    break;
   }
  }
  if (cancelFlag) continue;

  //ret[returnSize] = (char*) malloc(strlen(words[i]) * sizeof(char));
  ret[*returnSize] = (char *)words[i];
  *returnSize += 1;

 }

 return ret;
}

int main (int argc, char *argv[]) {

 return 0;
}
