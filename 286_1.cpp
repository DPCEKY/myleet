class Solution {
public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    if(rooms.empty())
      return;
    int m = rooms.size();
    int n = rooms[0].size();
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(rooms[i][j] == 0)
          calDis(rooms, m, n, i, j);
      }
    }
    return;
  }

  void calDis(vector<vector<int>>& rooms, int m, int n, int i, int j) {
    if(rooms[i][j] == -1)
      return;
    // up: i - 1
    if(i > 0) {
      if(rooms[i - 1][j] > rooms[i][j] + 1) {
        rooms[i - 1][j] = rooms[i][j] + 1;
        calDis(rooms, m, n, i - 1, j);
      }
    }
    // down: i + 1
    if(i + 1 < m) {
      if(rooms[i + 1][j] > rooms[i][j] + 1) {
        rooms[i + 1][j] = rooms[i][j] + 1;
        calDis(rooms, m, n, i + 1, j);
      }
    }
    //left: j - 1
    if(j > 0) {
      if(rooms[i][j - 1] > rooms[i][j] + 1) {
        rooms[i][j - 1] = rooms[i][j] + 1;
        calDis(rooms, m, n, i, j - 1);
      }
    }
    //right: j + 1
    if(j + 1 < n) {
      if(rooms[i][j + 1] > rooms[i][j] + 1) {
        rooms[i][j + 1] = rooms[i][j] + 1;
        calDis(rooms, m, n, i, j + 1);
      }
    }
    return;
  }
};
