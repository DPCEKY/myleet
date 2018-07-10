class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    if(nums.size() == 0)
      return 0;
    table.resize(target + 1);
    for(int i = 0; i < target + 1; i++) {
      table[i] = -1;
    }
    table[0] = 1;
    return DP(nums, target);
  }

  int DP(vector<int>& nums, int target) {
    if(table[target] != -1)
      return table[target];
    int res = 0;
    for(int i = 0; i < nums.size(); i++) {
      if(target >= nums[i])
        res += DP(nums, target - nums[i]);
    }
    table[target] = res;
    return res;
  }
  
private:
  std::vector<int> table;
};
