class Solution {
private:
#define MOD 1000000007

public:
    int concatenatedBinary(int n) {
      long long res = 0;
      int len = 0;

      for (int i = 1; i <= n; i++) {
        if (i & (i-1) == 0) len++;
        res = ((res << len) | i) %MOD;
      }

      return res;
        
    }
};
