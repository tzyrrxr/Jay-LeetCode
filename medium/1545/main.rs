impl Solution {
    pub fn find_kth_bit(n: i32, k: i32) -> char {
        if n == 1 {
            return '0';
        }
        let len = 1 << n;

        if len / 2 == k {
            '1'
        } else if len / 2 > k {
            find_kth_bit (n-1, k)
        } else {
            let preBit = find_kth_bit (n-1, len-k);
            if preBit == '1' {'0'} else {'1'}
        }
        
    }
}
