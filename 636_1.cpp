class Solution {
public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    std::vector<int> res;
    res.resize(n);
    std::stack<std::pair<int, int>> s;
    for(int i = 0; i < logs.size(); i++) {
      auto num = atoi(logs[i]);
      auto pos = logs[i].find_first_of(':');
      auto status = logs[i][pos + 1];
      pos = logs[i].find_first_of(':', pos + 1);
      auto time = stoi(logs[i].substr(pos));

      if(status == 's')
        s.push({num, time});
      else {
        auto pair = s.top();
        s.pop();
        if(!s.empty()) {
          auto prev = s.top();
          if(pair.first == prev.first)
            continue;
          res[prev.first] -= time - pair.second + 1;
        }
        res[num] += time - pair.second + 1;
      }
    }
    return res;
  }
}
