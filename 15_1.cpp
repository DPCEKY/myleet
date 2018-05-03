class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::unordered_map<int, std::list<int>> map;
    vector<vector<int>> result;

    for(int i = 1; i < nums.size(); i++) {
    
      for(int j = 0; j < i; j++) {
        int sum = nums[i] + nums[j];
        if(map.find(sum) == map.end()) {
          std::list<int> list;
          list.push_back(nums[j]);
          map.emplace(sum, list);
        }
        else {
          map[sum].push_back(nums[j]);
        }
      }

      if(map.find(-nums[i]) != map.end()) {
        auto vlist = map[ -nums[i] ];
        for(auto k = vlist.begin(); k != vlist.end(); k++) {
          vector<int> ans {*k, 0 - *k - nums[i], nums[i]};
          result.push_back(ans);
        }
      }

    }
  return result;

  }
};

