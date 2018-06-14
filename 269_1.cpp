class Solution {
public:
  string alienOrder(vector<string>& words) {
    if(words.size() == 0)
      return "";
    string res;
    vector<bool> table(26, false);
    int pre = -1;

    for(int i = 0; i < words.size(); i++) {
      if(words[i].size() == 0)
        continue;
      if(res.empty() || table[words[i][0] - 'a'] == false) {
        res.push_back(words[i][0]);
        pre++;
        table[words[i][0]] - 'a' == true;
      }
      else if(words[i][0] != res[pre]) {
        // cout << "i = " << i << ", pre = " << pre << endl;
        return "";
      }
    }

    for(int i = 1; i < words.size(); i++) {
      for(int j = 1; j < words[i].size(); j++) {
        if(words[i][j - 1] == words[i - 1][j - 1]) {
          cout << "i = " << i << ", j = " << j << endl;
          if(words[i][j] == words[i - 1][j])
            continue;
          if(!valid(res, words[i - 1][j], words[i][j]))
            return "";
          break;
        }
        else
          break;
      }
    }
    return res;
  }

  bool valid(std::string& in, char a, char b) {
    int ai, aj;
    for(int i = 0; i < in.size(); i++) {
      if(in[i] == a)
        ai = i;
      else if(in[i] == b)
        bi = i;
    }
    
    return true;
  }
};

