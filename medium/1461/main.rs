impl Solution {
    pub fn has_all_codes(s: String, k: i32) -> bool {
        let len = s.len();
        let mut possible = 1 << k;
        let tmp = possible;
        let mut hash = vec![false; possible];
        let mut val = 0;

        for i in 0..len {
            val = ((val << 1) & !tmp) + (s.as_bytes()[i] - b'0') as usize;
            if i+1 >= k as usize && hash[val] == false {
                hash[val] = true;
                possible -= 1;
                if possible == 0 {
                    return true;
                }
            }
        }
        
        false
    }
}
