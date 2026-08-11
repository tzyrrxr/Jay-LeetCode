impl Solution {
    pub fn concatenated_binary(n: i32) -> i32 {
        let mut res: i64 = 0;
        let mut len: i64 = 0;
        let MOD: i64 = 1_000_000_007;

        for i in 1..=n {
            if (i & (i-1)) == 0 {
                len += 1;
            }
            res = ((res << len) | (i as i64)) % MOD;
        }
        
        res as i32
    }
}
