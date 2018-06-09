class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int right = 0, left = 0;
    int sum = 0, length = 0;
        
    while(right < nums.size() && sum < s) {
      sum += nums[right];
      right++;
    }
    if(sum < s)
      return length;
    else if(right == nums.size()) {
      while(sum - nums[left] >= s) {
        sum -= nums[left];
        left++;
      }
      return right - left;
    }
    
    length = right - left;
    while(right < nums.size()) {
      sum += nums[right];
      right++;
      while(sum - nums[left] >= s) {
        sum -= nums[left];
        left++;
      }
      if(right - left < length)
        length = right - left;
    }
    return length;
  }
};
