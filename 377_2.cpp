class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    if(nums.size() == 0)
      return 0;
    vector<int> table;
    table.resize(target + 1);
    table[0] = 1;
    for(int i = 1; i < target + 1; i++) {
      int res = 0;
      for(int j = 0; j < nums.size(); j++) {
        if(nums[j] <= i)
          res += table[i - nums[j]];
      }
      table[i] = res;
    }
    return table[target];
  }
};
