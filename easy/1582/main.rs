impl Solution {
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
        let mut cnt = 0;
        let m = mat.len();
        let n = mat[0].len();
        let mut rowCnt = vec![0; m];
        let mut colCnt = vec![0; n];

        for i in 0..m {
            for j in 0..n {
                if (mat[i][j] == 1) {
                    rowCnt[i] +=1;
                    colCnt[j] +=1;
                }
            }
        }

        for i in 0..m {
            if rowCnt[i] == 1 {
                for j in 0..n {
                    if mat[i][j] == 1 && colCnt[j] == 1 {
                        cnt +=1;
                    }
                }
            }
        }

        cnt
        
    }
}
