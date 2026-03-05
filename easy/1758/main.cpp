class Solution {
public:
    int minOperations(string s) {
      int first0 = 0;
      int first1 = 0;

      for (int i = 0; s[i] != '\0'; i++) {
        // Start from '0' for the first element.
        if (s[i] != (i % 2 == 0 ? '0' : '1')) {
          first0++;
        }
      }
        
      first1 = s.size() - first0;

      return first0 < first1 ? first0 : first1;

    }
};
