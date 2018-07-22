class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    std::vector<int> res;
    if(nums.size() < k * 3)
      return res;
    std::vector<int> A;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {      
      if(i < k - 1)
        sum += nums[i];
      else if(i == k - 1) {
        sum += nums[i];
        A.push_back(sum);
      }
      else {
        sum -= nums[i - k];
        sum += nums[i];
        A.push_back(sum);
      }
    }

    std::vector<int> B, C;
    int m = 0;
    for(int i = 0; i < A.size(); i++) {
      if(A[i] > m) {
        B.push_back(i);
        m = A[i];
      }
      else
        B.push_back(B.back());
    }
    C.resize(A.size());
    m = 0;
    for(int i = A.size() - 1; i >= 0; i--) {
      if(A[i] >= m) {
        C[i] = i;
        m = A[i];
      }
      else
        C[i] = C[i + 1];
    }
    
    m = 0;
    for(int i = k; i < A.size() - k; i++) {
      if(A[B[i - k]] + A[i] + A[C[i + k]] > m) {
        m = A[B[i - k]] + A[i] + A[C[i + k]];
        res = {B[i - k], i, C[i + k]};
      }
    }
    return res;
  }
};
