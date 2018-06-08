class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    bool insordel = 0, rep = 0;
    if(s.size() == t.size()) {
      rep = 1;
    }
    else if(s.size() == t.size() + 1 || s.size() + 1 == t.size()) {
      insordel = 1;
    }
    else {
      return false;
    }

    int si = 0, ti = 0;
    while(true) {
      if(si == s.size() && ti == t.size()) {
        break;
      }
      if(s[si] != t[ti]) {
        if(rep == 1) {
          rep = 0;
          si++;
          ti++;
        }
        else if(insordel == 1) {
          insordel = 0;
          if(s.size() > t.size()) {
            si++;
          }
          else {
            ti++;
          }
        }
        else {
          return false;
        }
      }
    }
    return (insordel == 0) && (rep == 0);
  }
};
