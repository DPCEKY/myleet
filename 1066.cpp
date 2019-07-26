class Solution {
public:
  int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    int min_sum = ~(1 << 31);
    int curr_sum = 0;
    vector<bool> bikes_used(bikes.size(), false);
    int worker_index = 0;
    getMinDistSum(workers, bikes, min_sum, curr_sum, bikes_used, worker_index);
    return min_sum;
  }

  void getMinDistSum(vector<vector<int>>& workers, vector<vector<int>>& bikes, int& min_sum, int curr_sum, std::vector<bool>& bikes_used, int worker_index) {
    if(curr_sum >= min_sum) {
      return;
    }
    if(worker_index >= workers.size()) {
      min_sum = min(min_sum, curr_sum);
      return;
    }

    for(int i = 0; i < bikes.size(); i++) {
      if(bikes_used[i]) {
        continue;
      }
      bikes_used[i] = true;
      int dist = abs(workers[worker_index][0] - bikes[i][0]) + abs(workers[worker_index][1] - bikes[i][1]);
      getMinDistSum(workers, bikes, min_sum, curr_sum + dist, bikes_used, worker_index + 1);
      bikes_used[i] = false;
    }
    
  }
};
