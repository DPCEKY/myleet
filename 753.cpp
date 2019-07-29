class Solution {
public:
  string final_str;
  string crackSafe(int n, int k) {
    std::set<string> explored;
    std::string start;
    for(int i = 0; i < n; i++) {
      start += '0';
    }
    explored.insert(start);
    dfs(start, explored, pow(k, n), n, k);
    return final_str;
  }
  
  bool dfs(string res, std::set<string>& explored, int total, int n, int k) {
    if(explored.size() >= total)  {
      final_str = res;
      return true;
    }
    int len = res.size();
    auto sub = res.substr(len - n + 1, n - 1);
    
    for(int i = 0; i < k; i++) {
      auto next_str = sub + to_string(i);
      if(explored.count(next_str) != 0) {
        continue;
      }
      explored.insert(next_str);

      if(dfs(res + to_string(i), explored, total, n, k)) {
        return true;
      }
      
      explored.erase(next_str);

    }
    return false;
  }
};
