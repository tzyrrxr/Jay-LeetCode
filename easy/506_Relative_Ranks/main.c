#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
 char **HashTable = (char**) malloc((1000000 + 1) * sizeof(char*));
 char **ret = (char**) malloc(scoreSize * sizeof (char*));
 int order = 0;
 for (int i = 0; i < scoreSize; i++) {
  HashTable[score[i]] = (char*)calloc('\0', 15 * sizeof(char));
  HashTable[score[i]] = "1";
 }

 order++;
 for (int i = 1000000+1; i > 0; i--, order++) {
  if (strlen(HashTable[i])) {
   switch (order) {
    case 1:
     strcpy(HashTable[i], "Gold Medal");
     break;
    case 2:
     strcpy(HashTable[i], "Silver Medal");
     break;
    case 3:
     strcpy(HashTable[i], "Bronze Medal");
     break;
    default: 
     sprintf(HashTable[i], "%d", order);
     break;
   }
  }
 }

 for (int i = 0; i < scoreSize; i++) {
  ret[i] = (char*) calloc('\0', 15 * sizeof(char));
  strcpy(ret[i], HashTable[score[i]]);
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
