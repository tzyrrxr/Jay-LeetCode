class Solution {
public:
    int minimumCost(vector<int>& nums) {
       int min = nums[0];
       vector<int> a(2, INT_MAX);
       for (int i = 1; i < nums.size(); i++) {
         if (nums[i] < a[0]) { 
            a[1] = a[0];
            a[0] = nums[i];
         } else if (nums[i] < a[1]) {
            a[1] = nums[i];
         }
       }
        
       return min + a[0] + a[1];
    }
};
