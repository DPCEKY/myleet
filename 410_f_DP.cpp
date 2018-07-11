class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    std::vector<std::vector<std::pair<int, int>>> DP;
    // {largest sum, sum of last subarray}
    DP.resize(n + 1);
    for(int i = 0; i < n + 1; i++) {
      DP[i].resize(m + 1);
      DP[i][0] = {0, 0};
    }
    DP[0][1] = {0, 0};
    for(int i = 1; i < n + 1; i++) {
      auto sub = DP[i - 1][1].first + nums[i - 1];
      DP[i][1] = {sub, sub};
    }

    for(int i = 1; i < n + 1; i++) {
      for(int j = 2; j <= min(m, i); j++) {
        if(i == j) {
          auto largest_sum = max(DP[i - 1][j - 1].first, nums[i]);
          DP[i][j] = {largest_sum, nums[i]};
        }
        else {
          // line i - 1 : j subs in all
          auto largest_sum_1 = max(DP[i - 1][j].first, DP[i - 1][j].second + nums[i]);
          // line i - 1 : j - 1 subs
          auto largest_sum_2 = max(DP[i - 1][j - 1].first, nums[i]);
          if(largest_sum_1 <= largest_sum_2) { // line i - 1 : j subs in all
            if(DP[i - 1][j].first > DP[i - 1][j].second + nums[i])
              DP[i][j] = {DP[i - 1][j].first, DP[i - 1][j].second + nums[i]};
            else
              DP[i][j] = {DP[i - 1][j].second + nums[i], DP[i - 1][j].second + nums[i]};
          }
          else { // line i - 1 : j - 1 subs
            if(DP[i - 1][j - 1].first > nums[i])
              DP[i][j] = {DP[i - 1][j - 1].first, nums[i]};
            else
              DP[i][j] = {nums[i], nums[i]};
          }
        }
      }
    }
    return DP[n][m].first;
  }
};
