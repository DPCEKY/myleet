class Solution {
public:
  double new21Game(int N, int K, int W) {
    if(K == 0) {
      return 1;
    }
    else if(K > N || N >= K + W) {
      return 0;
    }
    else if(K == 1) {
      return N <= W ? (double)N / (double)W : 0;
    }
    
    std::vector<double> dp(N + 1, 0);
    double res = 0;
    dp[0] = 1;
    dp[1] = 1.0 / W;
    
    double sub_sum = dp[0] + dp[1];
    for(int i = 2; i <= K + W - 1 && i <= N; i++) {
      dp[i] = sub_sum * 1.0 / W;
      if(i < K) {
        sub_sum += dp[i];
      }
      if(i - W >= 0) {
        sub_sum -= dp[i - W];
      }
      if(i >= K && i <= N) {
        res += dp[i];
      }
    }

    
    // for(int i = 0; i <= K; i++) {
    //   std::cout << "dp[" << i << "] = " << dp[i] << std::endl;
    // }
    return res;
  }
};






