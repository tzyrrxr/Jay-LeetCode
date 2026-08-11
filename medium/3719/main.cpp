class Solution {
public:
    int longestBalanced(vector<int>& nums) {
      std::unordered_map<int, int> hash;
      int maxLen = 0;

      for (int i = 0; i< nums.size(); i++) {
        hash.clear();
        int uniOdd = 0, uniEven = 0;
        for (int j = i; j< nums.size(); j++) {
          if (hash[nums[j]] == 0 && (nums[j] & 1)) {
            uniOdd++;
          } else if (hash[nums[j]] == 0) {
            uniEven++;
          }
          hash[nums[j]]++;

          if (uniEven == uniOdd) {
            maxLen = max(maxLen, j-i+1);
          }
        }
        
      }

      return maxLen;
        
    }
};
