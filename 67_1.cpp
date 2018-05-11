class Solution {
public:
  string addBinary(string a, string b) {
    auto arit = a.rbegin();
    auto brit = b.rbegin();

    string out;
    int carry = 0;
    while(arit != a.rend() && brit != b.rend()) {
      int res = carry + (*arit - '0') + (*brit - '0');
      carry = res / 2;
      res = res % 2;
      out.push_back('0' + res);
      arit++;
      brit++;
    }

    while(arit != a.rend()) {
      int res = carry + (*arit - '0');
      carry = res / 2;
      res = res % 2;
      out.push_back('0' + res);
      arit++;
    }

    while(brit != b.rend()) {
      int res = carry + (*brit - '0');
      carry = res / 2;
      res = res % 2;
      out.push_back('0' + res);
      brit++;
    }
    
    if(carry != 0)
      out.push_back('1');

    string result;
    std::copy(out.crbegin(), out.crend(), std::back_inserter(result));
    return result;

  }
};
