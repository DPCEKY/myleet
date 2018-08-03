class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    int N = graph.size();
    vector<bool> visited(N, false);
    vector<int> group(N. -1);
    for(int i = 0; i < N; i++) {
      if(visited[i] == false) {
        group[i] = 0;
        std::queue<int> q;
        for(auto j : graph[i]) {
          visited[j] = true;
          group[j] = !group[i];
          q.push(j);
        }
        while(!q.empty()) {
          int node = q.front();
          q.pop();
          for(auto j : graph[node]) {
            if(visited[j] == false) {
              visited[j] = true;
              group[j] = !group[node];
              q.push(j);
            }
            else if(group[j] == group[node])
              return false;
          }
        }
      }
    }
    return true;
  }
};
