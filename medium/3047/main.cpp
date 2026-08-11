#pragma optimization("-O3")

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
      int n = bottomLeft.size();
      int side = 0;

      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          int w = fmin(topRight[i][0], topRight[j][0]) - fmax(bottomLeft[i][0], bottomLeft[j][0]);
          if (w <= 0) continue;
          int h = fmin(topRight[i][1], topRight[j][1]) - fmax(bottomLeft[i][1], bottomLeft[j][1]);
          if (h > 0) {
            side = fmax(side, fmin(w,h));
          }
          
        }
      }
        
      return (long long)side * side;
    }
};
