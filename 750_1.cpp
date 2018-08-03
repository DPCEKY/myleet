class Solution {
public:
  int countCornerRectangles(vector<vector<int>>& grid) {
    if(grid.empty() || grid.size() < 2 || grid[0].size() < 2)
      return 0;
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    for(int i = 0; i < m - 1; i++) {
      for(int j = 1; j < m; j++) {
        int left = -1;
        int cur_res = 1;
        for(int k = 0; k < n; k++) {
          if(grid[i][k] == 0 || grid[j][k] == 0)
            continue;
          else if(left == -1) {
            left = k;
            continue;
          }
          res += cur_res;
          cur_res++;
        }
      }
    }
    return res;
  }
};

