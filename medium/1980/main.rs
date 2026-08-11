impl Solution {
    pub fn find_different_binary_string(nums: Vec<String>) -> String {
        let mut res = String::new();

        for (i, s) in nums.iter().enumerate() {
            let c = if s.as_bytes()[i] == b'0' {'1'} else {'0'};
            res.push(c);
        }

        res
        
    }
}
