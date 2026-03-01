class Solution {
public:
    int minPartitions(string n) {
      int max = 0;

      for (const auto &c : n) {
        if ('9'== c) {
          return 9;
        }
        if (c - '0' > max) {
          max = c - '0';
        }
      }
        
      return max;

    }
};
