class Solution {
public:
  int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    if(n == 0)
      return 0;
    int k = costs[0].size();
    vector<vector<int>> plan;
    plan.resize(n);

    int pre_min, pre_sec_min, pre_pos;
    int cur_min, cur_sec_min, cur_pos;
    for(int i = 0; i < n; i++) {
      plan[i].resize(k);

      cur_min = INT_MAX;
      for(int j = 0; j < k; j++) {
        if(i == 0)
          plan[0][j] = costs[0][j]; 
        else if(j != pre_pos) 
          plan[i][j] = pre_min + costs[i][j];
        else
          plan[i][j] = pre_sec_min + costs[i][j];
        if(plan[i][j] < cur_min) {
          cur_min = plan[i][j];
          cur_pos = j;
        }
      }
      
      cur_sec_min = INT_MAX;
      for(int j = 0; j < k; j++) {
        if(j == cur_pos)
          continue;
        if(cur_sec_min > plan[i][j])
          cur_sec_min = plan[i][j];
      }

      pre_min = cur_min;
      pre_sec_min = cur_sec_min;
      pre_pos = cur_pos;
    }
    return pre_min;
  }
};
