class Solution {
public:
  int totalHammingDistance(vector<int>& nums) {
    if(nums.size() < 2)
      return 0;
    int res = 0;
    for(int i = 0; i < 32; i++) {
      int count = 0;
      for(int j = 0; j < nums.size(); j++)
        count += (nums[j] >> i) & 1;
      res += count * (nums.size() - count);
    }
    return res;
  }
};

