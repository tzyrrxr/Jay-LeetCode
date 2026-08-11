impl Solution {
    pub fn minimum_difference(nums: Vec<i32>, k: i32) -> i32 {
        let mut diff = i32::MAX;
        let k = k as usize;
        let mut nums = nums;
        nums.sort_unstable();

        for i in 0..nums.len()-k+1 {
            diff = diff.min(nums[i+k-1]-nums[i]);
        }
        
        diff
    }
}
