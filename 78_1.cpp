class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.empty()) {
      return res;
    }
    
    vector<int> vec;
    sub(nums, 1, vec, res);
    
    vec.push_back(nums[0]);
    sub(nums, 1, vec, res);
    
    return res;
  }
  
  void sub(vector<int>& nums, int pos, vector<int> vec, vector<vector<int>>& res) {
    if(pos == nums.size()) {
      res.push_back(vec);
      return;
    }
    sub(nums, pos + 1, vec, res);
    vec.push_back(nums[pos]);
    sub(nums, pos + 1, vec, res);
  }
};
