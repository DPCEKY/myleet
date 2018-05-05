class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    unsigned int counter = 0;
    if(nums.size() == 0) {
      return counter;
    }
    else if(nums.size() == 1) {
      counter++;
      return counter;
    }
    
    counter++;
    int last_value = nums[0];
    for(int i = 1; i < nums.size(); i++) {
      int new_value = nums[i];
      if(new_value > last_value) {
        nums[counter] = nums[i];
        last_value = nums[counter];
        counter++;
      }
    }
    return counter;
  }
};
