class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int row = grid.size();
    if(row == 0) {
      return 0;
    }
    int col = grid[0].size();    
    vector<std::pair<char, char>> first, sec;

    if(grid.size() == 0) {
      return 0;
    }
    else if(grid.size() >= 1) {
      cout << "grid[0]: " << endl;
      first = findSub(grid[0]);
      if(row == 1) {
        return first.size();
      }
    }
    
    int res = 0;
    for(int i = 1; i < row; i++) {
      if(first.empty()) {
        cout << "i = " << i << ", grid[i]: " << endl;
        first = findSub(grid[i]);
        continue;
      }

      while(!first.empty()) {
        auto pair = first.back();
        char left = pair.first;
        char right = pair.second;
        first.pop_back();
        bool connected = false;
        char sec_left, sec_right;

        while(right != left - 1) {
          if(grid[i][right] == '1' && grid[i - 1][right] == '1') {
            if(connected == false) {
              connected = true;
              sec_right = right;
            }
            else {
              sec_left = right;
            }
          }
          right--;
        }
        if(!connected) {
          res++;
          continue;
        }
        else if(sec_left == left) {
          while(sec_left >= 0 && grid[i][sec_left] == '1') {
            sec_left--;
          }
          sec_left++;
        }
        sec.insert(sec.begin(), {sec_left, sec_right});
      }
      
      auto pair = first.back();
      char right;
      if(pair == first.end()) {
        right = 0;
      }
      else {
        right = pair.second;
      }
      while(right <= sec_left - 1) {
        
        
      }
      

      sec.swap(first);
      sec.clear();
      if(first.size() <= 1) {
        continue;
      }
      
      auto last = first.back();
      first.pop_back();
      while(first.size() != 0) {
        auto last2 = first.back();
        first.pop_back();
        if(last2.second <= last.first) {
          last = {min(last2.first, last.first), last.second};
        }
        else {
          sec.insert(sec.begin(), last);
          last = last2;
        }
      }
      sec.insert(sec.begin(), last);
      sec.swap(first);
      first.clear();
    }
    res += first.size();
    return res;
  }
private:
  vector<std::pair<char, char>> findSub(vector<char> g) {
    vector<std::pair<char, char>> res;
    int i = 0;
    for(i = 0; i < g.size(); i++) {
      int start, end;
      if(g[i] == '1') {
        start = i;
        while(i < g.size()) {
          if(g[i] == '0') {
            end = i - 1;
            break;
          }
          else if(i == g.size() - 1) {
            end = i;
            break;
          }
          i++;
        }
        res.push_back({start, end});
        cout << "i = "<< i << ", (" << start << ", " << end << ") ";
      } 
    }
    cout << endl;
    return res;
  }
};

