class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
      vector<int> res;

      for (auto num : nums) {
        int p = 1;
        for (; (p & num) != 0; p <<= 1);
        p >>= 1;
        if (num != 2) {
          res.push_back(num - p);
        } else {
          res.push_back(-1);
        }
      }
        
      return res;
    }
};
