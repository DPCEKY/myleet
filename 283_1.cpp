class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    if(nums.empty())
      return nums;
    int i = 0, j = 0;
    while(j < nums.size()) {
      while(nums[i] != 0)
        i++;
      j = i;
      while(j < nums.size() && nums[j] == 0)
        j++;
      if(j >= nums.size())
        return;
      nums[i] = nums[j];
      nums[j] = 0;
    }
    return;
  }
};
