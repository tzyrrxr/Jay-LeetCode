#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestCommonSubsequence (char* text1, char* text2) {
  int **table;
  int len1 = strlen(text1);
  int len2 = strlen(text2);
  int max = 0;

  table = (int**) malloc (len1 * sizeof(int*));
  for (int i = 0; i < len1; i++) table[i] = (int*) calloc (len2, sizeof(int));

  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      if (text1[i] == text2[j]) {

        if (i - 1 < 0 || j - 1 < 0) {
          table[i][j] = 1;
        } else {
          table[i][j] = table[i-1][j-1] + 1;
        }

      } else {
        if (i - 1 < 0 && j - 1 < 0) {
          table[i][j] = 0;
        } else if (i - 1 < 0) {
          table[i][j] = 0 > table[i][j-1] ? 0 : table[i][j-1];
        } else if (j - 1 < 0) {
          table[i][j] = table[i-1][j] > 0 ? table[i-1][j] : 0;
        } else {
          table[i][j] = table[i-1][j] > table[i][j-1] ? table[i-1][j] : table[i][j-1];
        }
      }
    }
  }

  return table[len1 - 1][len2 - 1];

}

int main () {
  int ret = 0;
  char t1[] = "gtgtgatcg";
  char t2[] = "actgattag";

  ret = longestCommonSubsequence (t1, t2);

  return 0;
}
