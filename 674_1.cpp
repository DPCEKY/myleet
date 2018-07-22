class Solution {
public:
  int findLengthOfLCIS(vector<int>& nums) {
    if(nums.empty())
      return 0;
    if(nums.size() < 2)
      return 1;

    int len = 1, res = 1;
    int prev = nums[0];
    for(int i = 1; i < nums.size(); i++) {
      if(prev < nums[i]) {
        len++;
        res = max(len, res);
      }
      else {
        len = 1;
      }
      prev = nums[i];
    }
    return res;
  }
};
