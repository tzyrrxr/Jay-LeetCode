#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      int maxArea = INT_MIN;
      int h = matrix.size();
      int w = matrix[0].size();
      vector<int> continuousH(w, 0);

      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          continuousH[j] = (matrix[i][j] == '1') ? continuousH[j]+1: 0;
        }
        
        for (int start = 0; start < w; start++) {
          int minH = INT_MAX;
          int maxW = INT_MIN;
          for (int end = start; end < w; end++) {
            minH = min(minH, continuousH[end]);
            maxW = end -start + 1;
            maxArea = max(maxArea, minH*maxW);
          }
        }
      }

      return maxArea;

    }
};
