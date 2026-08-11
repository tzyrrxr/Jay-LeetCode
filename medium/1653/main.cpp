class Solution {
public:
    int minimumDeletions(string s) {
      int n = s.length();
      int res = INT_MAX;
      vector<int> Delete_a(n);
      for (int i = n-1, a_count = 0; i >= 0; i--) {
        Delete_a[i] = a_count;
        if (s[i] == 'a') a_count++;
      }

      for (int i = 0, b_count = 0; i < n; i++) {
        res = min(b_count+Delete_a[i], res);
        if (s[i] == 'b') b_count++;
      }

      return res;

    }

};
