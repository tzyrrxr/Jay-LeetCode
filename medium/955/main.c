#include <string.h>
#include <stdbool.h>

int minDeletionSize(char** strs, int strsSize) {
  int res = 0;
  int n = strsSize;
  int len = strlen(strs[0]);
  // only check valid to n-1 times. isSorted[0] == true means strs[0][] -> strs[1][] is sorted 
  bool *isSorted = (bool*) calloc(n-1, sizeof(bool));

  for (int i = 0; i < len; i++) {
    int valid_column = 1;
    // check column whether is legal
    // isSorted[] == false means need to check whether strs[j][] <= strs[j+1][]
    for (int j = 0; j < n-1; j++) {
      if (isSorted[j] == 0 && strs[j][i] > strs[j+1][i]) {
        res++;
        valid_column = 0;
        break;
      }
    }

    if (valid_column) {
      // update isSorted array
      for (int j = 0; j < n-1; j++) {
        // Although strs[j][i] == strs[j+1][i] is valid. 
        // Keep tracking
        if (strs[j][i] < strs[j+1][i]) {
          isSorted[j] = 1;
        }
      }
    }
  }

  free(isSorted);

  return res;

}
