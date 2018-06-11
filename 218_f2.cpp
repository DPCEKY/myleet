class Solution {
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> res;
    vector<int> city;
    for(auto building : buildings) {
      int left = building[0];
      int right = building[1];
      int h = building[2];
      if(city.size() < right + 1)
        city.resize(right + 1);

      while(left < right) {
        city[left] = max(city[left], h);
        left++;
      }
    }

    int pre_h = 0;
    for(int i = 0; i < city.size(); i++) {
      if(city[i] > pre_h) {
        res.push_back({i, city[i]});
      }
      else if(city[i] < pre_h) {
        res.push_back({i, city[i]});
      }
      pre_h = city[i];
    }
    return res;
  }
};
