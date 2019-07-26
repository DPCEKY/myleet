class Solution {
public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> res;
    long s = (long)lower;
    for(auto& num_int : nums) {
      long num = num_int;
      if(num == s) {
        s++;
      }
      else if(num == s + 1) {
        res.push_back(constructString(s));
        s = num + 1;
      }
      else if(num > s) {
        res.push_back(constructString(s, num - 1));
        s = num + 1;
      }
    }
    // std::cout << s << ", " << lower << std::endl;
    if(s == (long)upper) {
      res.push_back(constructString(s));
    }
    else if(s < (long)upper && s >= lower) {
      res.push_back(constructString(s, (long)upper));
    }
    return res;
  }

  string constructString(int s) {
    return std::to_string(s);
  }
  
  string constructString(int s, int e) {
    return std::to_string(s) + "->" + std::to_string(e);
  }
};


