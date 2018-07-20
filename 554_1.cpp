class Solution {
public:
  int leastBricks(vector<vector<int>>& wall) {
    if(wall.size() == 1 && wall[0].size() == 1)
      return 1;
    std::unordered_map<int, int> map;
    int gap_maxn = 0;
    for(int i = 0; i < wall.size(); i++) {
      gap = 0;
      for(int j = 0; j < wall[i].size() - 1; i++) {
        gap += wall[i][j];
       
        if(map.find(gap) == map.end()) {
          map.emplace(gap, 1);
        }
        else
          map[gap]++;

        if(map[gap] > gap_maxn)
          gap_maxn = map[gap];

      }
    }
    return wall.size() - gap_maxn;
  }
};
