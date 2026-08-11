class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
      int side = 1;
      int wcurr = 1, hcurr = 1;
      int wmax = 1, hmax = 1;

      sort(hBars.begin(), hBars.end());
      sort(vBars.begin(), vBars.end());

      for (int i = 1; i < hBars.size(); i++) {
        hmax = fmax(hmax, hcurr = hBars[i] - hBars[i - 1] == 1 ? hcurr+1 : 1);
      }

      for (int i = 1; i < vBars.size(); i++) {
        wmax = fmax(wmax, wcurr = vBars[i] - vBars[i - 1] == 1 ? wcurr+1 : 1);
      }

      side = fmin(hmax, wmax) + 1;

        
      return side * side;
    }
};
