class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    if(nums.size() < 2)
      return false;
    
    std::unordered_map<int, int> map;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
      if(k == 0) {
        if(nums[i] != 0 || nums[i + 1] != 0)
          continue;
        return true;
      }

      sum += nums[i];
      auto res = sum % k;
      if(res == 0 && i > 0)
        return true;
      if(map.find(res) != map.end()) {
        if(i - map[res] > 1)
          return true;
      }
      else {
        map.insert({res, i});
      }
    }
    return false;
  }
};

