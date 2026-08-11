class Solution {
public:
    bool hasAllCodes(string s, int k) {
      int len = s.size();
      int possible = 1 << k;
      vector<bool> hash(possible, 0);  
      int val = 0;

      for (int i = 0, tmp = possible; i < len; i++) {
        val = ((val << 1) & ~tmp) + s[i] - '0';
        if (i+1 >= k && hash[val] == false) {
          hash[val] = true;
          possible--;
          if (possible == 0) return true;
        }
      }

      return false;
        
    }
};
