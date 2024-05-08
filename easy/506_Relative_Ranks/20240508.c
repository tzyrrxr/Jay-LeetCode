#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
 int len = scoreSize;
 char** ret = (char**) malloc(scoreSize * sizeof(char*));

 for (int i = 0; i < len; i++) {
  int r = 1;
  for (int j = 0; j < len; j++) if (score[i] < score[j]) r++;
  ret[i] = (char*) calloc(13, sizeof(char));
  switch (r) {
   case 1:
    strcpy(ret[i], "Gold Medal");
    break;

   case 2:
    strcpy(ret[i], "Silver Medal");
    break;

   case 3:
    strcpy(ret[i], "Bronze Medal");
    break;

   default: 
    sprintf(ret[i], "%d", r);
    break;
  }
 }

 *returnSize = len;
 return ret;
}


int main (void) {

 return 0;
}
