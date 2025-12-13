#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define GDB 0

#define CODE "jPSkpeR","kRCxJQH","VWUzRYk","vDkXJ7l","IQ9oYqD","nTqj15k"
#define BUSINESSlINE "grocery","pharmacy","pharmacy","restaurant","grocery","grocery"
#define ISACTIVE true,true,true,true,true,true

// exclude r
void sortingArr (char** a, int l, int r) {
  for (int i = l; i < r-1; i++) {
    for (int j = i+1; j < r; j++) {
      int pt = 0;
      char *tmp;
      while (a[i][pt] == a[j][pt] && a[i][pt] != '\0' && a[j][pt] != '\0') pt++;
      if (a[i][pt] > a[j][pt]) {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      } 
    }


  }
}

bool isValidData (char* password) {
  if (password[0] == '\0') return false;
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= '0' && password[i] <= '9') continue;
    else if (password[i] >= 'a' && password[i] <= 'z') continue;
    else if (password[i] >= 'A' && password[i] <= 'Z') continue;
    else if (password[i] == '_') continue;

    return false; 
  }
  return true;
}

int getRank (char* s) {
  int rank = -1;

  if (!strcmp(s, "electronics")) {
     rank = 0;
  }
  if (!strcmp(s, "grocery")) {
     rank = 1;
  }
  if (!strcmp(s, "pharmacy")) {
     rank = 2;
  }
  if (!strcmp(s, "restaurant")) {
     rank = 3;
  }

  return rank;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** validateCoupons(
  char** code, 
  int codeSize, 
  char** businessLine, 
  int businessLineSize, 
  bool* isActive, 
  int isActiveSize, 
  int* returnSize
  ) {

  int activeCnt = 0;
  int top = 0;
  char** ret = NULL;
  int* rank = NULL;
  int rank0, rank1, rank2, rank3 = 0;
  rank0 = rank1 = rank2 = rank3;

  for (int i = 0; i < isActiveSize; i++) {
    if (isActive[i] && isValidData(code[i]) && getRank(businessLine[i]) != -1) activeCnt++;
  }

  if (!activeCnt) {
    *returnSize = 0;
    return ret;
  }

  ret = (char**) malloc(activeCnt * sizeof(char*));
  rank = (int*) malloc(activeCnt * sizeof(int));

  for (int i = 0; i < isActiveSize; i++) {
    if (isActive[i] && isValidData(code[i]) && getRank(businessLine[i]) != -1) {
      ret[top] = code[i];
      // -1 is invalid
      rank[top] = getRank(businessLine[i]);
      switch (rank[top]) {
        case 0:
          rank0++;
          break;

        case 1:
          rank1++;
          break;

        case 2:
          rank2++;
          break;

        case 3:
          rank3++;
          break;

        default:
         break;
      }
      top++;
    }
  }

  // sorting
  for (int i = 0; i < activeCnt-1; i++) {
    char *tmpStr;
    int tmpRank;
    for (int j = i+1; j < activeCnt; j++) {
      if (rank[i] > rank[j]) {
        tmpRank = rank[i];
        rank[i] = rank[j];
        rank[j] = tmpRank;

        tmpStr = ret[i];
        ret[i] = ret[j];
        ret[j] = tmpStr;
      }
    }
  }

  if (rank0 > 1) {
    sortingArr(ret, 0, rank0);
  } 
  if (rank1 > 1) {
    sortingArr(ret, rank0, rank0+rank1);
  } 
  if (rank2 > 1) {
    sortingArr(ret, rank0+rank1, rank0+rank1+rank2);
  } 
  if (rank3 > 1) {
    sortingArr(ret, rank0+rank1+rank2, rank0+rank1+rank2+rank3);
  }
    
  free(rank);
  *returnSize = activeCnt;

  return ret;

}

#if GDB == 1
int main () {
  char *code[] = {CODE};
  int codeSize = sizeof(code) / sizeof(char*);
  char *businessLine[] = {BUSINESSlINE};
  int businessLineSize = sizeof(businessLine) / sizeof(char*);
  bool isActive[] = {ISACTIVE};
  int isActiveSize = sizeof(isActive) / sizeof(bool);
  int* returnSize = NULL;

  validateCoupons (code, codeSize, businessLine, businessLineSize, isActive, isActiveSize, returnSize);

  return 0;
}
#endif
