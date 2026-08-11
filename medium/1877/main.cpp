class Solution {
public:
    int minPairSum(vector<int>& nums) {
      int max = INT_MIN;
        
      sort(nums.begin(), nums.end());

      for (int i = 0, j = nums.size()-1; i<j; i++,j--) max = nums[i]+nums[j] > max ?nums[i]+nums[j] : max;

      return max;
    }
};
