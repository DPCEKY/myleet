class Solution {
public:
  string longestPalindrome(string s) {
    int max_len = -1;
    int left = 0, tmp_left = 0;
    for(int i = 0; i < s.size(); i++) {
      int len = findPalindrome(s, i, tmp_left);
      if (max_len < len) {
        max_len = len;
        left = tmp_left;
      }
    }
    return s.substr(left, max_len);
  }

  int findPalindrome(string src, int pos, int& left) {
    int len = 0;
    while(pos + len < src.size() && pos - len >= 0 && src[pos + len] == src[pos - len]) {
      len++;
    }
    int right_pos = pos + 1, len_even = 0;
    while(right_pos + len_even < src.size() && pos - len_even >= 0 && src[right_pos + len_even] == src[pos - len_even]) {
      len_even++;
    }
    if(len * 2 - 1 > len_even * 2) {
      left = pos - len + 1;
      return len * 2 - 1;
    } else {
      left = pos - len_even + 1;
      return len_even * 2;
    }
  }
};

