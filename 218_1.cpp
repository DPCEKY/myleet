class Solution {
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> res;
    vector<int> city;
    for(auto building : buildings) {
      int left = building[0];
      int right = building[1];
      int h = building[2];
      if(city.size() < right + 2)
        city.resize(right + 2);

      while(left < right) {
        city[left + 1] = max(city[left + 1], h);
        left++;
      }
    }

    int pre_h = 0;
    for(int i = 0; i < city.size() - 1; i++) {
      if(city[i + 1] > pre_h) {
        res.push_back({i, city[i + 1]});
      }
      else if(city[i + 1] < pre_h) {
        res.push_back({i, city[i + 1]});
      }
      pre_h = city[i + 1];
    }
    return res;
  }
};
