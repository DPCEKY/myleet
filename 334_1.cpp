class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    if(nums.size() <= 2)
      return false;
    int min, start = 0, sec = 1;
    while(sec < nums.size() && nums[start] >= nums[sec]) {
      start++;
      sec++;
    }
    if(sec >= nums.size())
      return false;
    
    min = start;
    for(int i = sec + 1; i < nums.size(); i++) {
      if(nums[i] > nums[sec])
        return true;
      else if(nums[i] < nums[sec] && nums[i] > nums[start])
        sec = i;
      
      if(nums[i] < nums[min])
        min = i;
      else if(nums[i] > nums[min] && nums[i] < nums[start]) {
        start = min;
        sec = i;
      }
    }
    return false;
  }
};
