#define PERCISION 1e-5

class Solution {
private:
    bool Check (vector<vector<int>>& squares, double totalArea, double height) {
      double aboveArea = 0.0;
      for (auto &square : squares) {
        if (square[1] > height) {
          aboveArea += (double) square[2] * (double)square[2];
        } else if (square[1] + square[2] > height){
          aboveArea += (double) square[2] * (double) (square[1] + square[2] - height);
        }
      }
      return aboveArea * 2 > totalArea;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
      double totalArea = 0;
      double height = INT_MIN;
      double low = 0;
      double ans = 0;

      for (auto &square : squares) {
        totalArea += (double)square[2] * (double)square[2];
        height = fmax(square[1] + square[2], height);
      }

      while (height - low > PERCISION) {
        ans = (low + height) / 2;
        if (Check(squares, totalArea, ans)) {
          low = ans;
        } else {
          height = ans;
        }
      }

      return ans;
        
    }
};
