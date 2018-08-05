class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    if(nums.size() < 3)
      return res;
    for(int i = 0; i < nums.size() - 2; i++) {
      if(i == 0 || nums[i] != nums[i - 1]) {
        int j = i + 1, k = nums.size() - 1;
        int tar = -nums[i];
        while(j < k) {
          int nj = nums[j], nk = nums[k];
          if(nj + nk == tar) {
            res.push_back({nums[i], nums[j], nums[k]});
            while(j < k && nk == nums[k])
              k--;
            while(j < k && nj == nums[j])
              j++;
          }
          else if(nj + nk > tar)
            while(j < k && nk == nums[k])
              k--;
          else
            while(j < k && nj == nums[j])
              j++;
        }
      }
    }
    return res;
  }
};
