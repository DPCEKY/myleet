class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    vector<int> above, below;
    int seed = nums[0];
    for(int i = 1; i < nums.size(); i++) {
      if(seed < nums[i]) {
        above.push_back(nums[i]);
      }
      else {
        below.push_back(nums[i]);
      }
    }

    if(above.size() > k - 1) {
      return findKthLargest(above, k);
    }
    else if(above.size() < k - 1) {
      return findKthLargest(below, k - above.size() - 1);
    }
    else
      return seed;
  }
};
