class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    if(n == 0)
      return 0;
    int m = grid[0].size;
    int res = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(grid[i][j] == '1') {
          res++;
          markIsland(grid, i, j);
        }
      }
    }
    return res;
  }

  void markIsland(vector<vector<char>>& grid, int i, int j) {
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
      return;
    else if(grid[i][j] == '0')
      return;
    grid[i][j] = '0';
    markIsland(grid, i - 1, j);
    markIsland(grid, i + 1, j);
    markIsland(grid, i, j - 1);
    markIsland(grid, i, j + 1);
  }
};
