class Solution {
public:
  bool validTree(int n, vector<pair<int, int>>& edges) {
    if(n <= 1)
      return true;

    std::unordered_set<int> set;
    for(int i = 0; i < n ; i++) {
      set.insert(i);
    }
    
    for(int i = 0; i < edges.size(); i++) {
      auto pair = edges[i];
      auto it_first = set.find(pair.first);
      auto it_second = set.find(pair.second);
      if(it_first == set.end() && it_second == set.end())
        return false;
      }
      if(it_first != set.end()) {
        set.erase(it_first);
      }
      if(it_second != set.end()) {
        set.erase(it_second);
      }
    }
    return set.empty();
  }
};
