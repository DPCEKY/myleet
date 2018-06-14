class Solution {
public:
  string alienOrder(vector<string>& words) {
    if(words.size() == 0)
      return "";
    std::string res;
    int pre = -1;
    int pre_line = -1;
    std::vector<bool> table(26, false);
    
    for(int i = 0; i < words.size(); i++) {
      for(int j = 0; j < words[i].size(); j++) {
        if(res.empty()) {
          res.push_back(words[i][j]);
          pre++;
          table[word[i][j] - 'a'] = true;
        }
        else {
          if(table[word[i][j] - 'a'] == false) {
            res.push_back(word[i][j]);
            pre = res.size() - 1;
            table[word[i][j] - 'a'] = true;
          }
          else if(word[i][j] == res[pre])
            continue;
          else{
            int pos = pre - 1;
            for(int k = pre; k < res.size(); k++) {
              if(res[k] == words[i][j]) {
                pos = k;
                break;
              }
            }
            if(pos == pre - 1)
              return "";
          }
        }
        if(j == 0)
          pre_line = pre;
      }
      pre = pre_line;
    }
    return res;
  }
};
