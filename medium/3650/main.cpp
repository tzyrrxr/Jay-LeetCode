// Dijkstra's algorithm

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
      vector<vector<pair<int, int>>> graph(n);
      vector<int> dist(n, INT_MAX); // distance of each node
      vector<bool> visited(n, false);
      // initialize min-heap priority queue
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap;

      for (auto &edge:edges) {
        int s = edge[0];
        int e = edge[1];
        int w = edge[2];
        graph[s].push_back({e, w});
        graph[e].push_back({s, w*2}); // create reverse edge with double weight

      }
      dist[0] = 0;
      minHeap.push({0, 0}); // (distance, node)

      while(!minHeap.empty()) {
        auto [curDist, node] = minHeap.top();
        minHeap.pop();
        if (node == n-1) return curDist;

        if (visited[node]) continue;
        visited[node] = true;

        for (auto &[endNode, weight]: graph[node]) {
          if (dist[node] + weight < dist[endNode]) {
            dist[endNode] = dist[node] + weight;
            minHeap.push({dist[endNode], endNode});
          }
          
        }
      }

      return -1;
        
    }
};
