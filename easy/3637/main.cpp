class Solution {
public:
    bool isTrionic(vector<int>& nums) {
      if (nums.size() <= 3) return false;
      int i = 1;
      bool flag = 0;

      for (int j = 0; j < 3; j++) {
         int mul = (j&1) ? -1 : 1;
         while (i < nums.size()) {
           if ((nums[i] - nums[i-1])*mul > 0) {
             i++;
             flag = 1;
             continue;
           }
           break;
         }
         if (flag == false) return false;
         flag = false;
      }

      return i == nums.size() ? true : false;
        
    }
};
