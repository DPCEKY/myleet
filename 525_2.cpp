class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    if(nums.size() < 2)
      return 0;
    int sum = 0;
    std::unordered_set<int> map;
    int len = 0;
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] == 0)
        sum -= 1;
      else
        sum += 1;
      
      if(sum == 0)
        len = i + 1;
      else {
        if(map.find(sum) != map.end())
          len = max(len, i - map[sum]);
        else
          map.insert(sum);
      }
    }
    return len;
  }
};
