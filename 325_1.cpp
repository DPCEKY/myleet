class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    if(nums.empty())
      return 0;

    int length = 0, max_len = 0;
    for(int i = 0; i < nums.size(); i++) {
      int sum = 0;
      length = 0;
      for(int j = i; j < nums.size(); j++) {
        sum += nums[i][j];
        length++;
        if(sum == k && length > max_len)
          max_len = length;
      }
    }
    return max_len;
  }
};
