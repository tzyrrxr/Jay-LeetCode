class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
      vector<int> ans;

      for (int num : nums) {
        ans.push_back(-1);
        for (int i = 0; i < num; i++) {
          if((i | i+1) == num) {
            ans.pop_back();
            ans.push_back(i);
            break;
          }
        }
      }
        
      return ans;
    }
};
