class Solution {
public:
  vector<string> expand(string S) {
    vector<string> res;
    dfs(res, 0, "", S);
    return res;
  }

  void dfs(vector<string>& res, int pos, std::string curr, std::string& s) {
    if(pos >= s.size()) {
      res.push_back(curr);
      return;
    }

    // std::cout << "curr = " << curr << ", pos = " << pos << std::endl;
    
    auto open_brace = s.find_first_of('{', pos);
    if(std::string::npos == open_brace) {
      curr += s.substr(pos);
      res.push_back(curr);
      return;
    }
    curr += s.substr(pos, open_brace - pos);
    auto close_brace = s.find_first_of('}', pos);

    vector<char> candidates;
    for(int i = open_brace + 1; i < close_brace; i += 2) {
      candidates.push_back(s[i]);
    }
    
    std::sort(candidates.begin(), candidates.end());
    for(int i = 0; i < candidates.size(); i++) {
      dfs(res, close_brace + 1, curr + candidates[i], s);
    }
  }
};


