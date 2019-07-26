class Solution {
public:
  int oddEvenJumps(vector<int>& A) {
    int N = A.size();
    
    std::vector<int> odd(N, 0), even(N, 0);
    odd[N - 1] = even[N - 1] = 1;
    // key, pos
    std::map<int, int> mymap;
    mymap.insert_or_assign(A[N - 1], N - 1);

    int res = 1;
    for(int i = N - 2; i >= 0; i--) {
      auto hi = mymap.lower_bound(A[i]);
      auto lo = mymap.upper_bound(A[i]);
      if(hi != mymap.end()) {
        even[i] = odd[hi->second];
        res += even[i];
      }
      
      
      if(lo != mymap.begin()) {
        lo--;        
        odd[i] = even[lo->second];
      }
      
      mymap.insert_or_assign(A[i], i);
    }

    // std::cout << "odd: ";
    // for(int i = 0; i < N; i++) {
    //   std::cout << odd[i] << ", ";
    // }
    // std::cout << std::endl << "even: ";
    // for(int i = 0; i < N; i++) {
    //   std::cout << even[i] << ", ";
    // }
    // std::cout << std::endl;
    return res;
  }
};


