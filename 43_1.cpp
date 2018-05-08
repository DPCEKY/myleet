// output '0' condition

class Solution {
public:
  unsigned long long int strtoi(string str) {
    unsigned long long int res = 0;
    for(int i = 0; i < str.size(); i++) {
      unsigned int num = (str[i] - '0');
      res += num * mypow(str.size() - i -1);
    }
    return res;
  }

  unsigned long long int mypow(int pow) {
    unsigned long long int res = 1;
    for(int i = 0; i < pow; i++) {
      res *= 10;
    }
    return res;
  }

  string multiply(string num1, string num2) {
    auto n1 = strtoi(num1);
    auto n2 = strtoi(num2);
    auto n3 = n1 * n2;

    if(n3 == 0)
      return "0";

    string result;
    for(int i = num1.size() + num2.size(); i > -1; i--) {
      unsigned long long int tmp = n3 / mypow(i);
      if(tmp != 0) {
        char x = '0' + tmp % 10;
        result.push_back(x);
      }
    }
    return result;
  }
};

