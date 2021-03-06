// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int left = 1, right = n, mid;
    while(left <= right) {
      mid = (left + right) >> 1;
      if(isBadVersion(mid))
        right = mid - 1;
      else
        left = mid + 1;
    }
    return right + 1;
  }
};
