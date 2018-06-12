class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int zeros = 0;
    int product = 1;
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] == 0)
        zeros++;
      else
        product *= nums[i];
    }
    
    vector<int> res;
    if(zeros >= 2) {
      vector<int> result(nums.size(), 0);
      return result;
    }
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] == 0)
        res.push_back(product);
      else if(zeros == 0)
        res.push_back(product / nums[i]);
      else
        res.push_back(0);
    }

    return res;
  }
};
