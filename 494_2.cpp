class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    if(nums.empty())
      return S == 0;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
      sum += nums[i];
    
    if((sum + S) % 2 != 0 || sum < S || -sum > S)
      return 0;
    sum += S;
    sum = sum / 2;
    
    std::vector<int> dp;
    dp.assign(sum + 1, 0);
    dp[0] = 1;
    
    for(int i = 1; i < nums.size() + 1; i++) {
      for(int j = sum; j >= 0; j--) {
        if(j >= nums[i - 1])
          dp[j] += dp[j - nums[i - 1]];
      }
    }
    return dp[sum];
  }
};

