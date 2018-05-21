class Solution {
public:
  bool isPalindrome(string s) {
    if(s.empty())
      return true;
    
    int begin = 0, end = s.size() - 1;
    while(begin < end) {
      while((s[begin] > 'z' || s[begin] < 'a') && (s[begin] > 'Z' || s[begin] < 'A') && (s[begin] > '9' || s[begin] < '0'))
        begin++;
      while((s[end] > 'z' || s[end] < 'a') && (s[end] > 'Z' || s[end] < 'A') && (s[end] > '9' || s[end] < '0'))
        end--;

      if(begin >= end)
        break;
      else if(tolower(s[begin++]) != tolower(s[end--]))
        return false;
    }
    return true;
  }
};

