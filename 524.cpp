class Solution {
public:
  string findLongestWord(string s, vector<string>& d) {
    string res;
    std::unordered_map<int, int> mymap;
    for(auto& c : s) {
      for(int i = 0; i < d.size(); i++) {
        if(mymap.count(i) != 0) {
          mymap[i] += (c == d[i][mymap[i]]);
        }
        else if(c == d[i][0]) {
          mymap[i] = 1;
        }

        if(mymap[i] >= d[i].size()) {
          if(res.size() < d[i].size() || ((res.size() == d[i].size()) && res > d[i])) {
            res = d[i];
          }
        }
      }
    }
    return res;
  }
};
