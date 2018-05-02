// Do not use st++ in for loop. do it separately
// '*' may represent zero times of previous char in pt
// '.*' matches all st
class Solution {
public:
  bool isMatch(string s, string p) {
    auto pt = p.begin();
    char pre_char = '\0';

    if(s.empty()) {
      if(pt == p.end())
        return true;
      else
        return false;
    }

    for(auto st = s.begin(); st != s.end(); st++) {
      if(pt == p.end())
        return false;

      if(*pt == *st || *pt == '.') {
        pre_char = *pt;
        pt++;
        continue;
      }
      else if(*pt == '*') {
        if(pre_char == '.')
          return true;
        else if(pre_char != *st) {
          pt++;
          st--;
          continue;
        }
        while(*pt == '*') {
          pt++;
          if(pt == p.end()) {
            do{
              st++;
            }while(*st == pre_char);
            
            if(st == s.end())
              return true;
            else
              return false;
          }

          if(*pt == pre_char) {
            char s_counter = 0;
            char p_counter = 1;

            do{
              s_counter++;
              st++;
            
            }while(*st == pre_char);
            
            do{
              pt++;
              if(*pt == '*')
                continue;
              p_counter++;
            }while(*pt == pre_char || *pt == '*');

            if(s_counter < p_counter) {
              return false;
            }

            if(st == s.end()) {
              if(pt == p.end())
                return true;
              else
                return false;
            }
            st--;
          }
          else {
            do{
              st++;
            }while(*st == pre_char);
            if(st == s.end())
              return false;
            st--;
          }
          
        }
        
      }
      else {
        pt++;
        if(*pt == '*')
          pt++;
        else
          return false;
      }
            
    }
    if(pt == p.end())
      return true;
    else return false;

  }
};

