impl Solution {
    pub fn sort_by_bits(arr: Vec<i32>) -> Vec<i32> {
        let mut arr = arr;
        arr.sort_by (|a, b| {
            let cnt_a = a.count_ones();
            let cnt_b = b.count_ones();

            if cnt_a == cnt_b {
                a.cmp(b)
            } else {
                cnt_a.cmp(&cnt_b)
            }
        });
        
        arr

    }
}
