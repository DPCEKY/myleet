class Solution {
public:
  bool isMatch(string s, string p) {
    if(p.empty())
      return s.empty();

    if(p.size() == 1)
      return (s.size() == 1) && (p[0] == s[0] || p[0] == '.');

    if(p[1] != '*') {
      if(s.empty())
        return false;
      return (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }
    else {
      if(s.empty())
        return isMatch(s, p.substr(2));
      else if(p[0] == s[0] || p[0] == '.'){
        if(isMatch(s, p.substr(2)))
          return true;
        return isMatch(s.substr(1), p);
      }
      else
        return isMatch(s, p.substr(2));
      
    }

  }
};
