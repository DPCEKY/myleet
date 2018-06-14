class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    if(n == 0)
      return 0;
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum += nums[i];
    }
    
    return (1 + n) * n / 2 - sum;
  }
};
