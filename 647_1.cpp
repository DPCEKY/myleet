class Solution {
public:
  int countSubstrings(string s) {
    if(s.empty())
      return 0;
    int size = s.size();
    std::vector<std::vector<bool>> dp;
    dp.resize(size);
    int res = 0;
    for(int i = 0; i < size; i++) {
      dp[i].resize(size);
      dp[i][i] = true;
      res++;
      if(i < size - 1 && s[i] == s[i + 1]) {
        res++;
        dp[i][i + 1] = true;
      }
      else if(i < size - 1)
        dp[i][i + 1] = false;
    }
    
    for(int k = 2; k < size; k++) {
      for(int i = 0; i + k < size; i++) {
        int j = i + k;
        dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
        if(dp[i][j] == true)
          res++;
      }
    }
    return res;
  }
};
/*
dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
(i + 1 <= j - 1, 0 <= i <= j - 2, j <= size - 1)
*/
