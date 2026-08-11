impl Solution {
    pub fn min_removal(nums: Vec<i32>, k: i32) -> i32 {
        let mut maxRange = 0;
        let mut s = 0;
        let mut n = nums.len();
        let mul: i64 = k as i64;
        let mut nums = nums;

        nums.sort_unstable();

        for e in 0..n {
            while s<=e && ((nums[e] as i64) > (nums[s] as i64)*mul) {
                s += 1;
            }
            if maxRange < e-s+1 {
                maxRange = e-s+1;
            }
        }

        (nums.len() as i32) - (maxRange as i32)
        
    }
}
