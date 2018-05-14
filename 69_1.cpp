// 1. take care of special cases: 0, 1. etc
// 2. multiplication overflow
class Solution {
public:
  int mySqrt(int x) {
    int left = 0;
    int right = x;
    if(left == right || left + 1 == right)
      return x;
    
    while(left + 1 < right) {
      int middle = (left + right) / 2;
      if(middle * middle > x) {
        right = middle;
      }
      else
        left = middle;
    }

    return left;
  }
};
