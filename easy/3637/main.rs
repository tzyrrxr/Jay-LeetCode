impl Solution {
    pub fn is_trionic(nums: Vec<i32>) -> bool {
        if nums.len() <= 3 {
            return false;
        }
        let mut flag = false;
        let mut i = 1;

        for j in 0..3 {
            let mul = if j&1 == 1 {-1} else {1};
            while i < nums.len() {
                if (nums[i] - nums[i-1]) * mul > 0 {
                    i += 1;
                    flag = true;
                    continue;
                }
                break;
            }
            if flag == false {
                return false;
            }
            flag = false;
        }

        // Does it reach the end of the array?
        i == nums.len()
        
    }
}
