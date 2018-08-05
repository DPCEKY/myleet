class Solution {
public:
  string multiply(string num1, string num2) {
    int N = num1.size() + num2.size();
    vector<int> res(N, 0);
    for(int i = num1.size() - 1; i >= 0; i--) {
      for(int j = num2.size() - 1; j >= 0; j--) {
        int mul = (num1[i] - '0') * (num2[j] - '0');
        int pos = num1.size() + num2.size() - 2 - i - j;
        while(mul != 0) {
          mul = mul + res[pos];
          res[pos] = mul % 10;
          mul /= 10;
          pos++;
        }
      }
    }
    bool is_zero = true;
    string result;
    for(int i = N - 1; i >= 0; i--) {
      if(res[i] != 0)
        is_zero = false;
      if(is_zero == false)
        result.push_back('0' + res[i]);
    }
    return result;
  }
};
