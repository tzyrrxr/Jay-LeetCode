class Solution {
private:
  vector<long long> dijkstra(char startChar,  vector<vector<pair<int, char>>> costMap) {
    vector<long long> res(26, LLONG_MAX);
    res[startChar-'a'] = 0;
    // create a minHeap to store the char and cost
    // cost first, char second
    priority_queue< pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>> > minHeap;

    minHeap.push({0, startChar});

    while (!minHeap.empty()) {
      long long currCost = minHeap.top().first;
      char currChar = minHeap.top().second;
      minHeap.pop();
      if (res[currChar - 'a'] < currCost) continue;

      // start to update the res
      for (auto &[converseCost, targetChar] : costMap[currChar - 'a']) {
        if (currCost + converseCost < res[targetChar - 'a']) {
          res[targetChar-'a'] = currCost + converseCost;
          minHeap.push({currCost + converseCost, targetChar});
        }

      }
    }

    return res;
  }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
      long long minCost = 0;

      // create a original to cost map
      vector<vector<pair<int, char>>> costMap(26);

      for (int i = 0; i < original.size(); i++) {
        costMap[original[i]-'a'].push_back({cost[i], changed[i]});
      }

      // Create a memo for the shorest path each of a-z converse to costMap 
      vector<vector<long long>> memo(26, vector<long long>(26, -1));
      for (int i = 0; i < 26; i++) {
        memo[i] = dijkstra(i+'a', costMap);
      }

      for (int i = 0; i < source.size(); i++) {
        if (memo[source[i]-'a'][target[i]-'a'] == LLONG_MAX) return -1;
        minCost += memo[source[i]-'a'][target[i]-'a'];
      }
        
      return minCost;

    }
};
