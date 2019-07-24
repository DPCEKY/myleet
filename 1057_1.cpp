class Solution {
public:
  vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    // <worker, bike>
    vector<vector<std::pair<int, int>>> bucket;
    bucket.resize(2000);
    vector<int> ans(workers.size(), -1), ans_bikes(bikes.size(), -1);
    for(int i = 0; i < workers.size(); i++) {
      for(int j = 0; j < bikes.size(); j++) {
        int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        bucket[dist].push_back(std::pair<int, int>(i, j));
      }
    }

    for(int i = 0; i < bucket.size(); i++) {
      std::sort(bucket[i].begin(), bucket[i].end(), [&](pair<int, int> a, pair<int, int> b){
        return a.first != b.first ? a.first < b.first : a.second < b.second;
      });
      for(int j = 0; j < bucket[i].size(); j++) {        
        int worker = bucket[i][j].first;
        int bike = bucket[i][j].second;
        
        if(ans[worker] == -1 && ans_bikes[bike] == -1) {
          ans[worker] = bike;
          ans_bikes[bike] = worker;
        }
      }
    }
    return ans;
  }
};

