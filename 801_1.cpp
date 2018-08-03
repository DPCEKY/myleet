class Solution {
public:
  int minSwap(vector<int>& A, vector<int>& B) {
    int fix = 0, swap = 1;
    for(int i = 1; i < A.size(); i++) {
      if(A[i - 1] >= A[i] || B[i - 1] >= B[i]) {
        // must swap right now
        int tmp = swap;
        swap = fix + 1;
        fix = tmp;
      }
      else if(A[i - 1] >= B[i] || B[i - 1] >= A[i]) {
        //must not swap
        fix = fix;
        swap = swap + 1;
      }
      else {
        // free to go
        int tmp = min(swap, fix);
        fix = tmp;
        swap = tmp + 1;
      }
    }
    return min(swap, fix);
  }
};
