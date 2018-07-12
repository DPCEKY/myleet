class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    if(s.empty())
      return res;
    std::queue<std::string> q;
    std::unordered_set<std::string> visited;
    if(isValid(s)) {
      res.push_back(s);
      return res;
    }
    q.push(s);
    visited.insert(s);
    int len = s.size();
    while(!q.empty()) {
      auto next = q.front();
      q.pop();
      if(len != s.size() && next.size() < len)
        continue;
      if(isValid(next)) {
        if(len == s.size())
          len = next.size();
        res.push_back(next);
        continue;
      }
      for(int i = 0; i < next.size(); i++) {
        if(next[i] != '(' && next[i] != ')')
          continue;
        auto sub = next.substr(0, i) + next.substr(i + 1, next.size());
        if(visited.find(sub) == visited.end()) {
          visited.insert(sub);
          q.push(sub);
        }
      }
    }
    return res;
  }

  bool isVaild(string s) {
    int num = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '(')
        num++;
      else if(s[i] == ')') {
        num--;
        if(num < 0)
          return false;
      }
    }
    return num == 0;
  }
};
