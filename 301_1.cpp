class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    if(s.empty())
      return res;
    int left_num = 0, right_num = 0;
    int inv_left_pos, inv_right_pos;
    int inv_left_num = 0, inv_right_num = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] != '(' && s[i] != ')')
        continue;

      if(s[i] == '(') {
        left_num++;
        if(left_num - right_num == 1)
          inv_left_pos = i;
      }
      else if(s[i] == ')')
        right_num++;

      if(right_num - left_num > inv_right_num) {
        inv_right_num = right_num - left_num;
        inv_right_pos = i;
      }
    }

    
  }
};
