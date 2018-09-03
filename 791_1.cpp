class Solution {
public:
  string customSortString(string S, string T) {
    vector<int> count(26, 0);
    for(int i = 0; i < T.size(); i++) {
      count[T[i] - 'a']++;
    }
    std::string res;
    for(int i = 0; i < S.size(); i++)
      while(count[S[i] - 'a']-- > 0)
        res += S[i];
    for(int i = 0; i < count.size(); i++)
      while(count[i]-- > 0)
        res += char('a' + i);
    return res;
  }
};

