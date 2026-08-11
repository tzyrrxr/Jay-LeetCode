impl Solution {
    pub fn minimum_cost(nums: Vec<i32>) -> i32 {
        let mut min = nums[0];
        let mut a = vec![i32::MAX, i32::MAX];
        for num in &nums[1..] {
            if *num < a[0] {
                a[1] = a[0];
                a[0] = *num;
            } else if *num < a[1] {
                 a[1] = *num;
            }
        }

        min + a[0] + a[1]
        
    }
}
