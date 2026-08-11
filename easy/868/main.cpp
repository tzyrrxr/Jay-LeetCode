#include <algorithm>

class Solution {
public:
    int binaryGap(int n) {
      int max_gap = 0;
      int cnt = 0;
      while (!(n&1) && n > 0) {
        n >>= 1;
      }

      while (n) {
        n >>= 1;
        cnt++;
        if (n&1) {
          max_gap = max(max_gap, cnt);
          cnt = 0;
        }
      }

      return max_gap;
        
    }
};
