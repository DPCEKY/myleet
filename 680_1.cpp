class Solution {
public:
  bool validPalindrome(string s) {
    if(s.size() < 2)
      return true;
    for(int i = 0; i < s.size() / 2; i++) {
      if(s[i] != s[s.size() - i - 1])
        return isPali(s, i + 1, s.size() - 1 - i) || isPali(s, i, s.size() - 2 - i);
    }
    return true;
  }

  bool isPali(std::string& s, int i, int j) {
    while(i < j) {
      if(s[i++] != s[j--])
        return false;
    }
    return true;
  }
};
