#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int CMP (const void *a, const void *b){
 int n = (*((int**)a))[2];
 int m = (*((int**)b))[2];
 return n-m;
}

void DSF (int *session, bool *hash, int** meetings, int time, int* ret, int* returnSize) {
  if (meetings[*session][2] != time) {
    (*session)--;
    return;
  }
  int i = *session;

  if ((hash[meetings[i][0]] == 0) && (hash[meetings[i][1]] == 0)) {
    (*session)++;
    DSF (session, hash, meetings, meetings[i][2], ret, returnSize);
  }

  if ((hash[meetings[i][0]] == 1) ^ (hash[meetings[i][1]] == 1)) {
    *returnSize += 1;
    if (hash[meetings[i][0]] == 0) {
      ret[*returnSize-1] = meetings[i][0];
      hash[meetings[i][0]] = 1;
    } else {
      ret[*returnSize-1] = meetings[i][1];
      hash[meetings[i][1]] = 1;
    }
  }


}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAllPeople(int n, int** meetings, int meetingsSize, int* meetingsColSize, int firstPerson, int* returnSize) {
  int *ret;
  int top = 0;
  bool *hash = (bool*) calloc(n, sizeof(bool));
  hash[0] = 1;

  *returnSize = 2;
  ret = (int*) calloc(n, sizeof(int));
  ret[1] = firstPerson;
  hash[firstPerson] = 1;

  qsort(meetings, meetingsSize, sizeof(int*), CMP);
  
  //for (int i = 0; i < meetingsSize; i++) {
  //  for (int j = i+1; j < meetingsSize-1; j++) {
  //    if (meetings[i][2] > meetings[j][2]) {
  //      int *tmp = meetings[i];
  //      meetings[i] = meetings[j];
  //      meetings[j] = tmp;
  //    }
  //  }
  //}
    
  for (int i = 0; i < meetingsSize; i++) {
    DSF (&i, hash, meetings, meetings[i][2], ret, returnSize);
  }

  free(hash);

  return ret;
}
