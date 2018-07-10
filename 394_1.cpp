class Solution {
public:
  string decodeString(string s) {
    pos = 0;
    if(s.empty())
      return "";
    string res;
    while(pos < s.size()) {
      int num = atoi(s.substr(pos).c_str());
      if(num != 0) {
        stack.push(num);
        int len = 2;
        while(num / 10 != 0) {
          len++;
          num = num / 10;
        }
        pos += len;
        auto sub_str = getStr(s);
        num = stack.top();
        stack.pop();
        do{
          res += sub_str;
          num--;
        } while(num > 0);
      }
      else {
        if(s[pos] == '[') {
          pos++;
          res += getStr(s);
        }
        else {
          res += s[pos++];
        }
      }
    }
    return res;
  }

  std::string getStr(std::string s) {
    if(s[pos] == ']') {
      pos++;
      return "";
    }

    std::string res;
    while(s[pos] != ']') {
      int num = atoi(s.substr(pos).c_str());
      if(num != 0) {
        stack.push(num);
        int len = 2;
        while(num / 10 != 0) {
          len++;
          num = num / 10;
        }
        pos += len;
        auto sub_str = getStr(s);
        num = stack.top();
        stack.pop();
        do{
          res += sub_str;
          num--;
        } while(num > 0);
      }
      else {
        if(s[pos] == '[') {
          pos++;
          res += getStr(s);
        }
        else {
          res += s[pos++];
        }
      }
    }
    pos++;
    return res;
  }
private:
  std::stack<int> stack;
  int pos;
};


