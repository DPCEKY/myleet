class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    if(prices.size() < 2)
      return 0;
    int p0 = 0, p1 = INT_MIN;
    for(int i = 0; i < prices.size(); i++) {
      int p_tmp = p0;
      p0 = max(p0, p1 + prices[i]);
      p1 = max(p1, p_tmp - fee - prices[i]);
    }
    return p0;
  }
};
