class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    long sum = 0, max = 0;
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] > max)
        max = nums[i];
      sum += nums[i];
    }
    long left = max, right = sum;
    while(left <= right) {
      long mid = (left + right) / 2;
      if(vaild(nums, mid, m)) // got more than m pieces
        left = mid + 1;
      else
        right = mid - 1;
    }
    return right + 1;
  }

  bool vaild(vector<int>& nums, int mid, int m) {
    int i = 0, n = 0;
    long sum = 0;
    while(i < nums.size()) {
      if(nums[i] + sum <= mid) {
        sum += nums[i];
        i++;
      }
      else if(nums[i] + sum > mid) {
        n++;
        sum = nums[i++];
      }
    }
    n++;
    return n > m;
  }
};

