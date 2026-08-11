#include <bit>

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

      sort(arr.begin(), arr.end(), 
          [](int a, int b) {
            int cnt1 = popcount((unsigned int)a);
            int cnt2 = popcount((unsigned int)b);

            if (cnt1 == cnt2) {
              return a<b;
            }

            return cnt1<cnt2;

          }); 

      return arr;
    }
};
