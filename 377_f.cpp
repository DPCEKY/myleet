class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    if(nums.empty())
      return 0;
    int res = 0;
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++) {
      set.insert(nums[i]);
    }

    for(int i = 1; i < target / nums[0] + 2; i++) {
      res += findCombination(nums, i, target);
    }
    return res;
  }

  int findCombination(vector<int>& nums, int len, int target) {
    if(nums[0] * len > target || nums.back() * len < target)
      return 0;

    if(len == 1)
      return set.find(target) != set.end() ? 1 : 0;

    int res = 0;
    for(int i = 0; i < nums.size(); i++) {
      if(target < nums[i])
        break;
      res += findCombination(nums, len - 1, target - nums[i]);
    }
    return res;
  }
private:
  std::unordered_set<int> set;
};
