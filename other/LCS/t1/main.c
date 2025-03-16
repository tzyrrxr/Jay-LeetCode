#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestCommonSubsequence (char* text1, char* text2) {
  int len1 = strlen(text1);
  int len2 = strlen(text2);
  int table[len1+1][len2+2];
  memset(table, 0, sizeof(table));

  for (int i = 1; i < len1 + 1; i++) {
    for (int j = 1; j < len2 + 1; j++) {
      if (text1[i-1] == text2[j-1]) {
        table[i][j] = table[i-1][j-1] + 1;
      } else {
        table[i][j] = table[i-1][j] > table[i][j-1] ? table[i-1][j] : table[i][j-1];
      }
    }

  }


  return table[len1][len2];

}

int main () {
  int ret = 0;
  char t1[] = "gtgtgatcg";
  char t2[] = "actgattag";

  ret = longestCommonSubsequence (t1, t2);

  return 0;
}
