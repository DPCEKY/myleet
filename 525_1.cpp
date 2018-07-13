class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    if(nums.size() < 2)
      return false;
    std::vector<int> table(nums.size(), 0);
    int len = 0, sum = 0;
    for(int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      table[i] = sum;
      if(i % 2 == 1 && sum == (i + 1) >> 1) {
        len = i + 1;
      }
      else {
        for(int j = i - len - 2; j >= 0; j -= 2) {
          if(sum - table[j] == (i - j) / 2)
            len = i - j;
        }
      }
      // cout << "sum[" << i << "] = " << sum << ", len = " << len << endl;
    }
    return len;
  }
};

