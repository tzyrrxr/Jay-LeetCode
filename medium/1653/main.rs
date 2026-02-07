impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let mut res: i32 = 0;
        let n = s.chars().count();
        let s_bytes = s.as_bytes();
        let mut Delete_a = vec![0; n];
        let mut a_count = 0;
        let mut b_count = 0;

        for i in (0..n).rev() {
            Delete_a[i] = a_count;
            if s_bytes[i] == b'a' {
                a_count += 1;
            }
        }

        res = a_count;

        for i in 0..n {
            res = std::cmp::min(Delete_a[i as usize]+b_count, res);
            if s_bytes[i] == b'b' {
                b_count += 1;
            }
        }

        res
        
    }
}
