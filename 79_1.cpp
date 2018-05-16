class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); i++) {
      for(int j = 0; j < board[0].size(); j++) {
        if(board[i][j] == word[0]) {
          search(board, word, i, j, 1);
        }

      }
    }

  }

  bool search(vector<vector<char>>& board, string& word, int i, int j, int num) {
    
  }

};
