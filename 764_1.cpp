class Solution {
public:
  int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    convertMines(mines);
    int msize = (N - 1) / 2 + 1;
    int res = 0;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if(checkMine(i, j, res + 1, N) == true)
          res++;
        if(res == msize)
          return res;
      }
    }
    return res;
  }

  void convertMines(vector<vector<int>>& mines) {
    for(int i = 0; i < mines.size(); i++) {
      map[mines[i][0]].insert(mines[i][1]);
    }
  }

  bool checkMine(int i, int j, int len, int N) {
    if(map.find(i) == map.end() || map[i].find(j) == map[i].end())
      return false;
    if(i - len + 1 < 0 || i + len - 1 > N - 1)
      return false;
    else if(j - len + 1 < 0 || j + len - 1 > N - 1)
      return false;
    for(int x = i - len + 1; x <= i + len - 1; x++) {
      if(map[x].find(j) != map[x].end())
        return false;
    }
    for(int y = j - len + 1; y <= j + len - 1; y++) {
      if(map[i].find(y) != map[i].end())
        return false;
    }
    return true;
  }
private:
  std::unordered_map<int, std::set<int>> map;
};
