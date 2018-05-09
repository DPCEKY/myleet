class Solution {
public:
  bool isMatch(string s, string p) {
    if(p.empty()) {
      return s.empty();
    }
    else if(s.empty()) {
      return p.empty() || (p[0] == '*' && isMatch(s, p.substr(1)));
    }
    else if(p.size() == 1) {
      if(p[0] == '*') {
        return true;
      }
      else if(s.size() == 1 && (s[0] == p[0] || p[0] == '?')) {
        return true;
      }
      else
        return false;
    }

    if(p[0] == '?') {
      return isMatch(s.substr(1), p.substr(1));
    }
    else if(p[0] != '*') {
      return (p[0] == s[0]) && isMatch(s.substr(1), p.substr(1));
    }
    else {
      return isMatch(s, p.substr(1)) || isMatch(s.substr(1), p);
    }

  }
}
;
