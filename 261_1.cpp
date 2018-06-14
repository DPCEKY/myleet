class Solution {
public:
  bool validTree(int n, vector<pair<int, int>>& edges) {
    std::unordered_set<int> set;
    std::vector<std::unordered_set<int>> adjlist;
    std::queue<int> q;

    adjlist.resize(n);
    for(int i = 0; i < n; i++) {
      set.insert(i);
    }
    for(int i = 0; i < edges.size(); i++) {
      auto pair = edges[i];
      adjlist[pair.first].insert(pair.second);
      adjlist[pair.second].insert(pair.first);
    }

    set.erase(set.find(0));
    q.push(0);
    while(!q.empty()) {
      int i = q.front();
      q.pop();
      for(auto it = adjlist[i].begin(); it != adjlist[i].end(); it++) {
        auto set_it = set.find(*it);
        if(set_it == set.end())
          return false;
        else
          set.erase(set_it);
        auto its = adjlist[*it].find(i);
        adjlist[*it].erase(its);
        q.push(*it);
      }
    }

    return set.empty();
  }
};

