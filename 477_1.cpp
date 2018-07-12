class Solution {
public:
  int totalHammingDistance(vector<int>& nums) {
    int res = 0;
    if(nums.size() < 2)
      return res;
    for(int i = 0; i < nums.size() - 1; i++) {
      for(int j = i + 1; j < nums.size(); j++) {
        res += hammingDis(nums[i], nums[j]);
      }
    }
    return res;
  }
  
  int hammingDis(int x, int y) {
    int z = x ^ y;
    int res = 0;
    for(int i = 0; i < 32; i++) {
      res += (z & 1);
      z = z >> 1;
    }
    return res;
  }
};

