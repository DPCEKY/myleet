class Solution {
public:
  double myPow(double x, int n) {
    if(x > -1 && x < 1) {
      x = 1 / x;
      n = -n;
    }

    int pn = n < 0? -n : n;
    int res = x;
    for(int i = 1; i < pn; i++) {
      res *= x;
    }

    if(n == 0) {
      return x != 0;
    }
    else if(n < 0) {
      return 1 / res;
    }
    else {
      return res;
    }

  }
};
