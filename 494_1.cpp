class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    if(nums.empty())
      return S == 0;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
      sum += nums[i];
    
    if((sum + S) % 2 != 0 || S > sum || S < -sum)
      return 0;
    sum += S;
    sum = sum / 2;
    
    std::vector<std::vector<int>> dp;
    dp.resize(nums.size() + 1);
    for(int i = 0; i < nums.size() + 1; i++) {
      dp[i].assign(sum + 1, 0);
      dp[i][0] = 1;
    }

    for(int j = 1; j < sum + 1; j++)
      dp[0][j] = 0;
    
    for(int i = 1; i < nums.size() + 1; i++) {
      for(int j = 0; j < sum + 1; j++) {
        if(j >= nums[i - 1])
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[nums.size()][sum];
  }
};

