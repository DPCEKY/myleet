class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    std::unordered_set<std::string> set;
    std::vector<std::vector<bool>> array;

    for(auto it : wordDict) {
      set.emplace(it);
    }
    array.insert(array.begin(), s.size(), std::vector<bool>(s.size(), false));

    for(int length = 0; length < s.size(); length++) {
      for(int i = 0; i < s.size() - length; i++) {
        int j = i + length;
        array[i][j] = false;
        for(int k = i; k < j; k++) {
          if(array[i][k] == true && array[k + 1][j] == true) {
            array[i][j] = true;
            break;
          }
        }
        if(set.find(s.substr(i, length + 1)) != set.end()) {
          array[i][j] = true;
        }
      }
    }
    
    return array[0][s.size() - 1];
  }
};

