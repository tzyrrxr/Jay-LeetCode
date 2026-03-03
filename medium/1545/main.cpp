class Solution {
public:
    char findKthBit(int n, int k) {
      if (n == 1) return '0';

      int len = 1 << n;

      if (len / 2 == k) {
        return '1';
      } else if (len / 2 > k) {
        return findKthBit(n-1, k);
      }

      int preBit = findKthBit(n-1, len-k);

      return preBit == '1' ? '0' : '1';
        
    }
};
