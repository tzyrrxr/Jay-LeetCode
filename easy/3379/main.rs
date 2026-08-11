impl Solution {
    pub fn construct_transformed_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len() as i32;
        let mut res = vec![0; n as usize];

        for i in 0..n {
            // usize in vector space
            res[i as usize] = nums[((i + nums[i as usize]).rem_euclid(n)) as usize]
        }
        
        res
    }
}
