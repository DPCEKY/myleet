class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    std::unordered_map<string, vector<string>> hash;

    for(int i = 0; i < strs.size(); i++) {
      auto str = strs[i];
      std::sort(str.begin(), str.end());
      if(hash.find(str) != hash.end()) {
        hash[str].push_back(strs[i]);
      }
      else {
        vector<string> value_str;
        value_str.push_back(strs[i]);
        hash.emplace(str, value_str);
      }
    }

    for(const auto& i : hash) {
      res.push_back(i.second);
    }

    return res;
  }
};
