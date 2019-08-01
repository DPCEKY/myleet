class Solution {
public:
  int expressiveWords(string S, vector<string>& words) {
    int res = 0;
    for(int i = 0; i < words.size(); i++) {
      for(int j = 0, k = 0; j < S.size() && k < words[i].size(); ) {
        if(S[j] == words[i][k]) {
          j++;
          k++;
        }
        else if(j >= 2 && S[j] == S[j - 1] && S[j] == S[j - 2]){
          j++;
        }
        else {
          break;
        }
      }
      if(j >= S.size() && k >= words[i].size()) {
        res++;
      }
    }
    return res;
  }
};
