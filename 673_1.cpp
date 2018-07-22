class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    if(nums.empty())
      return 0;
    else if(nums.size() == 1)
      return 1;
    
    std::vector<std::pair<int, int>> dp;
    dp.resize(nums.size());
    for(int i = 0; i < nums.size(); i++) {
      dp[i] = {1, 1};
    }
    
    int len = 0, count = 0;
    for(int i = 0; i < nums.size(); i++) {
      for(int j = 0; j < i; j++) {
        if(nums[j] < nums[i]) {
          if(dp[i].first == dp[j].first + 1) {
            dp[i].second += dp[j].second;
          }
          else if(dp[i].first < dp[j].first + 1) {
            dp[i].first = dp[j].first + 1;
            dp[i].second = dp[j].second;
          }
        }
      }
      if(dp[i].first > len) {
        len = dp[i].first;
        count = dp[i].second;
      }
      else if(dp[i].first == len)
        count += dp[i].second;
    }
    return count;
  }
};

