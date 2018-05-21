class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if(prices.size() < 2)
      return 0;

    int lowest = prices[0];
    int cur_pf = 0, pf = 0;
    for(int i = 1; i < prices.size(); i++) {
      if(prices[i] <= lowest) {
        lowest = prices[i];
        continue;
      }
      cur_pf = prices[i] - lowest;
      if(cur_pf > pf)
        pf = cur_pf;
    }
    return pf;
  }
};
