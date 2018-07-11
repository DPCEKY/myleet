class Solution {
public:
  Solution(vector<int> nums) {
    for(int i = 0; i < nums.size(); i++) {
      if(map.find(nums[i]) == map.end()) {
        std::vector<int> index;
        index.push_back(i);
        map.insert({nums[i], index});
      }
      else {
        std::vector<int>& index = map[nums[i]];
        index.push_back(i);
      }
    }
  }
    
  int pick(int target) {
    auto index = map[target];
    int size = index.size();
    int seed = rand() % size;
    return index[seed];
  }
private:
  std::unordered_map<int, std::vector<int>> map;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
