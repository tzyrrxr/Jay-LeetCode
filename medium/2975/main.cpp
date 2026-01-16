class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
      int side = -1;
      hFences.push_back(1);
      hFences.push_back(m);
      vFences.push_back(1);
      vFences.push_back(n);
      sort(hFences.begin(), hFences.end());
      sort(vFences.begin(), vFences.end());

      vector<long long> hDiffs;
      vector<long long> vDiffs;

      for (int i = 0; i < hFences.size(); i++) {
        for (int j = i+1; j < hFences.size(); j++) {
          hDiffs.push_back(hFences[j] - hFences[i]);
        }
      }

      for (int i = 0; i < vFences.size(); i++) {
        for (int j = i+1; j < vFences.size(); j++) {
          vDiffs.push_back(vFences[j] - vFences[i]);
        }
      }

      sort(hDiffs.begin(), hDiffs.end());
      sort(vDiffs.begin(), vDiffs.end());

      while (!hDiffs.empty() && !vDiffs.empty()) {
        if (hDiffs.back() == vDiffs.back()) {
          side = hDiffs.back();
          break;
        } else if (hDiffs.back() > vDiffs.back()) {
          hDiffs.pop_back();
        } else {
          vDiffs.pop_back();
        }

      }

      return side != -1 ? ((long long)side * side) % MOD: side;
        
    }
};
