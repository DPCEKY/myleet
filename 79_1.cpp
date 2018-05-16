class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    if(word.empty())
      return true;

    auto symbol = board;
    for(int i = 0; i < board.size(); i++) {
      for(int j = 0; j < board[0].size(); j++) {
        bool res;
        if(board[i][j] == word[0]) {
          symbol[i][j] = 0;
          res = search(board, symbol, word, i, j, 1);
        }
        if(res == true)
          return true;
        symbol[i][j] = board[i][j];
      }
    }
    return false;
  }

  bool search(vector<vector<char>>& board, vector<vector<char>>& symbol, string& word, int i, int j, int num) {
    if(num == word.size())
      return true;

    // up
    if(i > 0 && board[i - 1][j] == word[num]) {
      if(symbol[i - 1][j] != 0) {
        symbol[i - 1][j] = 0;
        auto res = search(board, symbol, word, i - 1, j, num + 1);
        if(res == true)
          return true;
        symbol[i - 1][j] = word[num];
      }
    }

    // down
    if(i < board.size() - 1 && board[i + 1][j] == word[num]) {
      if(symbol[i + 1][j] != 0) {
        symbol[i + 1][j] = 0;
        auto res = search(board, symbol, word, i + 1, j, num + 1);
        if(res == true)
          return true;
        symbol[i + 1][j] = word[num];
      }
    }

    // left
    if(j > 0 && board[i][j - 1] == word[num]) {
      if(symbol[i][j - 1] != 0) {
        symbol[i][j - 1] = 0;
        auto res = search(board, symbol, word, i, j - 1, num + 1);
        if(res == true)
          return true;
        symbol[i][j - 1] = word[num];
      }
    }

    // right
    if(j < board[0].size() - 1 && board[i][j + 1] == word[num]) {
      if(symbol[i][j + 1] != 0) {
        symbol[i][j + 1] = 0;
        auto res = search(board, symbol, word, i, j + 1, num + 1);
        if(res == true)
          return true;
        symbol[i][j + 1] = word[num];
      }
    }
    
    return false;
  }

};
