class Solution {
public:
  bool backspaceCompare(string S, string T) {
    int p = 0;
    for(int i = 0; i < S.size(); i++) {
      if(S[i] != '#') {
        S[p++] = S[i];
      }
      else {
        p--;
        p = p >= 0 ? p : 0;
      }
    }
    S.resize(p);
    p = 0;
    for(int i = 0; i < T.size(); i++) {
      if(T[i] != '#') {
        T[p++] = T[i];
      }
      else {
        p--;
        p = p >= 0 ? p : 0;
      }
    }
    T.resize(p);
    return S == T;
  }
};
