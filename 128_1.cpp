class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    std::unordered_map<int, int> map;
    int count = 0;

    for(int i = 0; i < nums.size(); i++) {
      if(map.find(nums[i]) != map.end()) {
        continue;
      }
      if(map.find(nums[i] - 1) != map.end()) {
        auto low = map[nums[i] - 1];
        if(low >= nums[i]) {
          continue;
        }
        map.erase(nums[i] - 1);
        map.emplace(nums[i], low);
        if(map.find(low) == map.end()) {
          map.emplace(low, nums[i]);
        }
        else {
          map[low] = nums[i];
        }
        auto c = nums[i] - low + 1;
        count = max(c, count);
      }
      
      if(map.find(nums[i] + 1) != map.end()) {
        auto up = map[nums[i] + 1];
        if(up <= nums[i]) {
          continue;
        }
        if(map.find(nums[i]) != map.end()) {
          map.erase(up);
          map.erase(nums[i] + 1);
          auto low = map[nums[i]];
          if(low <= nums[i]) {
            map[low] = up;
            map.erase(nums[i]);
            map.emplace(up, low);
            auto c = up - low + 1;
            count = max(c, count);
          }
        }
        else {
          map.erase(nums[i] + 1);
          map.emplace(nums[i], up);
          if(map.find(up) == map.end()) {
            map.emplace(up, nums[i]);
          }
          else {
            map[up] = nums[i];
          }
          auto c = up - nums[i] + 1;
          count = max(c, count);
        }
      }
      
      if(map.find(nums[i]) == map.end()) {
        map.emplace(nums[i], nums[i]);
        if(count == 0) {
          count++;
        }
      }
    }
    return count;
  }
};





