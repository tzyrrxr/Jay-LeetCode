#include <vector>

using namespace std;

class Solution {
public:
    // memoization table is m x n where m and n are lengths of s1 and s2
    int minimumDeleteSum(string s1, string s2) {
      int m = s1.length();
      int n = s2.length();
      vector<vector<int>> memo(n+1, vector<int> (m+1, 0));
      int totalSum = 0;
      for (char c : s1) totalSum += (int)c;
      for (char c : s2) totalSum += (int)c;
      for (int i = 1; i <=m; i++) {
        for (int j = 1; j <= n; j++) {
          if (s1[i-1] == s2[j-1]) {
            memo[j][i] = memo[j-1][i-1] + (int)s1[i-1]; // or s2[j-1]
          } else {
            memo[j][i] = memo[j-1][i] > memo[j][i-1] ? memo[j-1][i] : memo[j][i-1];
          }
        }
      }
        
      return totalSum - 2 * memo[n][m];
    }
};
