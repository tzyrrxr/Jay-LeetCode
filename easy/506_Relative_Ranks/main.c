#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
 int rank = 0 ;
 char** ret = (char **) malloc(scoreSize * sizeof(char*));
 for (int i = 0; i < scoreSize; i++) {
  rank = 1;
  for (int j = 0; j < scoreSize; j++) {
   if (score[i] < score[j]) rank++;
  }
  ret[i] = (char*) malloc(15 * sizeof(char));
  switch(rank) {
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
    sprintf(ret[i], "%d", rank);
    break;
  }

 }

 *returnSize = scoreSize;
 return ret;
}


int main (void) {
 int rank[] = {1, 7, 8, 3, 2};
 int retSize;
 findRelativeRanks (rank, 5, &retSize);

 return 0;
}
