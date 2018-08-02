class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> res;
    if(S.empty())
      return res;
    for(int i = 0; i < S.size(); i++) {
      auto c = S[i];
      if(c <= 'z' && c >= 'a') {
        lowertoUpper(res, s, i);
      }
      else if(c <= 'Z' && c >= 'A') {
        uppertolower(res, s, i);
      }
    }
    res.push_back(S);
    return res;
  }

  void lowertoUpper(vector<string>& res, string s, int pos) {
    s[pos] = s[pos] - 'a' + 'A';
    for(int i = pos + 1; i < s.size(); i++) {
      auto c = S[i];
      if(c <= 'Z' && c >= 'A') {
        uppertolower(res, s, i);
      }
    }
    res.push_back(s);
  }

  void uppertolower(vector<string>& res, string s, int pos) {
    s[pos] = s[pos] - 'A' + 'a';
    for(int i = pos + 1; i < s.size(); i++) {
      auto c = S[i];
      if(c <= 'z' && c >= 'a') {
        lowertoUpper(res, s, i);
      }
    }
    res.push_back(s);
  }
};
