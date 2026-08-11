impl Solution {
    pub fn min_partitions(n: String) -> i32 {
        let mut max = 0;

        for &b in n.as_bytes() {
            if b'9' == b {
                return 9;
            }
            if b - b'0' > max {
                max = b - b'0';
            }
        }
        
        max as i32
    }
}
