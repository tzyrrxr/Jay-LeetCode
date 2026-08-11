# LCS method
class Solution:
    # return int type
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m = len(s1)
        n = len(s2)
        # _ is a dummy variable
        memo = [[0 for _ in range(n+1)] for _ in range(m+1)]
        
        total = 0
        for i in range(m):
          total += ord(s1[i]) # convert to ASCII value
        for i in range(n):
          total += ord(s2[i]) 

        for i in range(1, m+1):
          for j in range(1, n+1):
            if s1[i-1] == s2[j-1]:
              memo[i][j] = memo[i-1][j-1] + ord(s1[i-1]) # or ord(s2[j-1])
            else:
              memo[i][j] = max(memo[i-1][j], memo[i][j-1])

        return total - 2 * memo[m][n]
