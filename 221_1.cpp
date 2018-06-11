class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.empty())
      return 0;

    int res = 0;
    for(int i = 0; i < matrix.size(); i++) {
      for(int j = 0; j < matrix[0].size(); j++) {
        int length = calSq(matrix, i, j, res);
        if(res < length)
          res = length;
      }
    }
    return res * res;
  }

  int calSq(vector<vector<char>>& m, int row, int col, int cur) {
    if(m.size() - row <= cur || m[0].size() - col <= cur)
      return 0;

    for(int i = row; i < row + cur; i++) {
      for(int j = col; j < col + cur; j++) {
        if(m[i][j] != '1')
          return 0;
      }
    }
    
    while(row + cur < m.size() && col + cur < m[0].size()) {
      for(int i = row; i < row + cur + 1; i++)
        if(m[i][col + cur] != '1')
          return cur;

      for(int j = col; j < col + cur; j++) {
        if(m[row + cur][j] != '1')
          return cur;
      }
      cur++;
    }
    return cur;
  }
};
