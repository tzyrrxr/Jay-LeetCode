class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
       vector<char> &a = letters;
       char res = a[0];
       int l = 0;
       int r = a.size() -1;

       while (l <= r) {
         int m = (l+r) >> 1;
         if (a[m] > target) {
            res = a[m];
            r = m-1;
         } else {
            l = m+1;
         }
       }
        
       return res;
    }
};
