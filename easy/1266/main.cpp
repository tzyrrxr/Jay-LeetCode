#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
      int minTime = 0;
      vector<vector<int>> &p = points;

      for (int i = 1; i < p.size(); i++) {
        int dx = p[i][0] - p[i-1][0];
        dx = dx >> 31 ? -dx : dx;
        int dy = p[i][1] - p[i-1][1];
        dy = dy >> 31 ? -dy : dy;
        minTime += max(dx, dy);
      }
        
      return minTime;

    }
};
