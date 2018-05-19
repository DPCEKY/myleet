class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::pair<int, int>> map;
    int count = 1;
    for(int i = 1; i < nums.size(); ) {
      while(i < nums.size() && nums[i] == nums[i - 1]) {
        count++;
        i++;
      }
      if(i == nums.size())
        break;
      map.push_back({nums[i - 1], count});
      count = 1;
      i++;
    }
    map.push_back({nums.back(), count});

    vector<vector<int>> res;
    vector<int> subs;
    subsets(0, map, subs, res);
    return res;
  }

  void subsets(int pos, std::vector<std::pair<int, int>>& map, vector<int> subs, vector<vector<int>>& res) {
    if(pos == map.size()) {
      res.push_back(subs);
      return;
    }

    subsets(pos + 1, map, subs, res);
    for(int i = 0; i < map[pos].second; i++) {
      subs.push_back(map[pos].first);
      subsets(pos + 1, map, subs, res);
    }
  }
};

