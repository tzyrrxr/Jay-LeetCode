#include <string.h>
#include <stdbool.h>

int minDeletionSize(char** strs, int strsSize) {
  int min = 0;
  int n = strsSize;
  int len = strlen(strs[0]);
  bool *delete = (bool *) calloc (len-1, sizeof(bool));

  for (int i = 0; i < len-1; i++) {
    for (int j = 0; j < n; j++) {
      if (!delete[i] && strs[j][i] < strs[j][i+1]) {
        min++;
        delete[i] = 1;
        break;
      }
    }
  }

  free(delete);

  return min;

}
