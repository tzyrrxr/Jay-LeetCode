impl Solution {
    pub fn min_operations(s: String) -> i32 {
        let mut first0 = 0;
        let s_bytes = s.as_bytes();

        for i in 0..s_bytes.len() {
            if s_bytes[i] != (if i % 2 == 0 {b'0'} else {b'1'}) {
                first0 += 1;
            }
        }

        let first1 = s_bytes.len() - first0;

        if first0 < first1 {first0 as i32} else {first1 as i32}
        
    }
}
