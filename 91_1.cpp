class Solution {
public:
  int numDecodings(string s) {
    if(s[0] == '0')
      return 0;

    if(s.size() < 2)
      return 1;

    if((s[0] == '2' && s[1] <= '6') || s[0] == '1') {
      int num1 = numDecodings(s.substr(1));
      int num2 = numDecodings(s.substr(2));
      return num1 + num2;
    }
    else {
      return numDecodings(s.substr(1));
    }
   
  }
};

