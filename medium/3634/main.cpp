#include <algorithm>
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
      int s = 0, e = 0;
      int maxRange = INT_MIN;
      sort(nums.begin(), nums.end());
      
      for (e = 0; e < nums.size(); e++) {
        while(s <= e &&
            (long long)nums[e] > (long long)nums[s] * k) 
        {
          s++;
        }
        if (maxRange < e-s+1) maxRange = e-s+1;
      }
        
      return nums.size() - maxRange;
    }
};
