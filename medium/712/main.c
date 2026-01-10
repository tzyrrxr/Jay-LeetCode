#include <string.h>

// LCS method
// Reference: https://ahsjlin.github.io/computer/algorithm/dynamic_programming/LCS_Longest_Common_Subsquence.html
// overview: Use LCS method to find the maximun ASCII sum of common subsequence
// then subtract it from the tatal ASCII sum of both strings to get the mininum delete sum.
int minimumDeleteSum(char* s1, char* s2) {
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  int memo[len2+1][len1+1];
  int totalSum = 0;
  for (int i = 0; i < len1; i++) totalSum += (int) s1[i];
  for (int i = 0; i < len2; i++) totalSum += (int) s2[i];

  // initialize memoization table
  // the first column
  for (int i = 0; i <= len1; i++) {
    memo[0][i] = 0;
  }
  // the first row
  for (int j = 0; j <= len2; j++) {
    memo[j][0] = 0;
  }

  // fill the memoization table
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      // common character
      // because the memo table is 1 index ahead, we need to -1 to get the character from the string
      if (s1[i-1] == s2[j-1]) {
        memo[j][i] = memo[j-1][i-1] + (int) s1[i-1]; // or plus s2[j-1], they are the sam
      } else {
        // not common character
        memo[j][i] = memo[j-1][i] > memo[j][i-1] ? memo[j-1][i] : memo[j][i-1];
      }
    }
  }

  // 2 times the LCS ASCII sum need to be subtracted from total sum
  return totalSum - 2*memo[len2][len1];
}
