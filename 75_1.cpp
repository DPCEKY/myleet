class Solution {
public:
  void sortColors(vector<int>& nums) {
    if(nums.empty())
      return;

    unsigned int zeros = 0, ones = 0, twos = 0;
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] == 0)
        zeros++;
      else if(nums[i] == 1)
        ones++;
      else
        twos++;
    }

    nums.clear();

    for(int i = 0; i < ones; i ++)
      nums.push_back(0, zeros);    
    for(int i = 0; i < ones; i ++)
      nums.push_back(1, ones);
    for(int i = 0; i < ones; i ++)
      nums.push_back(2, twos);

  }
};
