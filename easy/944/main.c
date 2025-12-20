#include <string.h>

int minDeletionSize(char** strs, int strsSize) {
  int res = 0;
  int len = strlen(strs[0]);
  int n = strsSize;

  while (len--) {
    char pt = strs[0][len];
    for (int i = 1; i < n; i++) {
      if (pt - strs[i][len] > 0) {
        res++;
        break; 
      }
      pt = strs[i][len];
    }
  }
    
  return res;

}
