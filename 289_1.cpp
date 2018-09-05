class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    if(board.empty() || board[0].empty())
      return;
    int m = board.size();
    int n = board[0].size();
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        update(board, i, j, m, n);
      }
    }
    return;
  }

  void update(vector<vector<int>>& board, int i, int j, int m, int n) {
    int alive = 0, last = board[i][j];
    // 0 1 2
    // 3 4 5
    // 6 7 8
    if(i - 1 >= 0 && j - 1 >= 0)
      alive += prev(board, i - 1, j - 1);
    if(i - 1 >= 0)
      alive += prev(board, i - 1, j);
    if(i - 1 >= 0 && j + 1 < n)
      alive += prev(board, i - 1, j + 1);
    if(j - 1 >= 0)
      alive += prev(board, i, j - 1);
    if(j + 1 < n)
      alive += prev(board, i, j + 1);
    if(i + 1 < m && j - 1 >= 0)
      alive += prev(board, i + 1, j - 1);
    if(i + 1 < m)
      alive += prev(board, i + 1, j);
    if(i + 1 < m && j + 1 < n)
      alive += prev(board, i + 1, j + 1);
    int cur = last;
    if(cur == 1) {
      if(alive < 2 || alive > 3)
        cur = 0;
    }
    else {
      if(alive == 3)
        cur = 1;
    }
    if(cur != last)
      map[i].insert(j);
    board[i][j] = cur;
  }

  int prev(vector<vector<int>>& board, int i, int j) {
    if(map[i] != map.end() && map[i].find(j) != map[i].end())
      return !board[i][j];
    return board[i][j];
  }
private:
  std::unordered_map<int, std::unordered_set<int>> map;
};
