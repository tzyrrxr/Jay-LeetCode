use std::collections::HashMap;

impl Solution {
    pub fn longest_balanced(nums: Vec<i32>) -> i32 {
        let mut hash = HashMap::new();
        let mut maxLen: i32 = 0;

        for i in 0..nums.len() {
            hash.clear();
            let mut uniEven: i32 = 0;
            let mut uniOdd: i32 = 0;
            for j in i..nums.len() {
                let hashKey = hash.entry(nums[j]).or_insert(0);
                if *hashKey == 0 {
                    if (nums[j] & 1) == 1 {
                        uniOdd += 1;
                    } else {
                        uniEven += 1;
                    }
                }
                *hashKey += 1;

                if uniOdd == uniEven {
                    maxLen = maxLen.max((j-i+1) as i32);
                }
            }
        }
        maxLen
    }
}
