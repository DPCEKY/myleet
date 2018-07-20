class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> t(26, 0);
    for(int i = 0; i < tasks.size(); i++) {
      t[tasks[i] - 'A']++;
    }
    std::sort(t.begin(), t.end());
    int res = (t[25] - 1) * (n + 1) + 1;
    int count = (t[25] - 1) * n;
    for(int i = 24; i > 0; i--) {
      if(t[25] == t[i]) {
        res++;
        if(t[i] - 1 <= count) {
          count -= t[i] - 1;
          continue;
        }
        else if(count > 0) {
          res += t[i] - count;
          count = 0;
        }
        else
          res += t[i];
      }
      else {
        if(t[i] <= count) {
          count -= t[i];
          continue;
        }
        else if(count > 0) {
          res += t[i] - count;
          count = 0;
        }
        else
          res += t[i];
      }
    }
    return res;
  }
};
