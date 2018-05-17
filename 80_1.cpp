class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if(nums.empty())
      return 0;
    
    int ins = 1, scan = 1;
    int last = nums[0], count = 1;
    for(scan = 1; scan < nums.size(); scan++) {
      if(nums[scan] == last && count < 2) {
        count++;
        nums[ins] = nums[scan];
        ins++;
      }
      else if(nums[scan] == last && count >= 2) {
        continue;
      }
      else {
        last = nums[scan];
        count = 1;
        nums[ins] = nums[scan];
        ins++;
      }
    }
    return ins;
    
  }
};
