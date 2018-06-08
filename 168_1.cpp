class Solution {
public:
  string convertToTitle(int n) {
    string res;

    while(n != 0) {
      n = n - 1;
      res.insert(0, 1, 'A' + n % 26);
      n = n / 26;
    }
    return res;
  }
};
