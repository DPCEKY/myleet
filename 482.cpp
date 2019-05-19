class Solution {
public:
  string licenseKeyFormatting(string S, int K) {
    int len = S.size() - 1;
    string res = "";
    int concated_len = 0;
    for(int i = len; i >= 0; i--) {
      if(S[i] == '-') {
        continue;
      }
      res = to_upper(S[i]) + res;

      concated_len++;
      if(concated_len == K) {
        if(i > 0)
          res = '-' + res;
        concated_len = 0;
      }
    }
    if(res[0] == '-')
      return res.substr(1);
    return res;
  }

  char to_upper(char c) {
    if(c >= 'a' && c <= 'z')
      return c - 'a' + 'A';
    else
      return c;
  }
};



