class Solution {
public:
  int hIndex(vector<int>& citations) {
    int num = citations.size();
    if(num == 0)
      return 0;

    int left = 0, right = num - 1;
    while(left <= right) {
      int mid = (left + right) / 2;
      if(citations[mid] >= num - mid)
        right = mid - 1;
      else
        left = mid + 1;
    }
    return num - (right + 1);
  }
};
