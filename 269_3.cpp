class Solution {
public:
  string alienOrder(vector<string>& words) {
    if(words.empty())
      return "";

    std::vector<std::unordered_set<char>> adj;
    std::vector<int> used(26, 2);
    
    adj.resize(26);
    char pre = words[0][0];
    
    for(int i = 0; i < words.size(); i++) {
      for(int j = 0; j < words[i].size(); j++) {
        used[words[i][j] - 'a'] = 0;
      }
    }
    
    for(int i = 1; i < words.size(); i++) {
      if(words[i][0] == pre) {
        for(int j = 1; j < words[i].size(); j++) {
          if(j >= words[i - 1].size())
            break;
          if(words[i][j] == words[i - 1][j])
            continue;
          adj[words[i - 1][j] - 'a'].insert(words[i][j]);
          break;
        }
        continue;
      }
      adj[pre - 'a'].insert(words[i][0]);
      pre = words[i][0];
    }

    string res;
    topo_sort(res, adj, used);
    return res;
  }

  void topo_sort(string& res, std::vector<std::unordered_set<char>>& adj, std::vector<int>& used) {

    std::vector<int> succeeding(26, 0);
    std::queue<char> q;
    for(int i = 0; i < 26; i++) {
      succeeding[i] = adj[i].size();
      if(succeeding[i] == 0)
        q.push('a' + i);
    }

    while(!q.empty()) {
      auto next = q.front();
      q.pop();
      if(used[next - 'a'] == 2)
        continue;
      used[next - 'a'] = 1;
      res.push_back(next);
      for(int i = 0; i < 26; i++) {
        if(adj[i].find(next) != adj[i].end()) {
          succeeding[i]--;
          adj[i].erase(next);
          if(succeeding[i] == 0)
            q.push(i + 'a');
        }
      }
    }
    for(int i = 0; i < 26; i++) {
      if(succeeding[i] != 0) {
        res.clear();
        return;
      }
    }
    for(int i = 0; i < res.size() / 2; i++) {
      auto tmp = res[res.size() - 1 - i];
      res[res.size() - 1 - i] = res[i];
      res[i] = tmp;
    }
    return;
  }

};

