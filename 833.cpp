class Solution {
public:
  string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
    std::vector<std::pair<int, int>> orders;
    for(int i = 0; i < indexes.size(); i++) {
      orders.push_back({indexes[i], i});
    }
    std::sort(orders.begin(), orders.end(), [&](pair<int, int> a, pair<int, int> b){
      return a.first > b.first;
    });

    for(int i = 0; i < orders.size(); i++) {
      int pos = orders[i].first;
      int index = orders[i].second;
      if(S.substr(pos, sources[index].size()) == sources[index]) {
        S = S.substr(0, pos) + target[index] + S.substr(pos + sources[index].size());
      }
    }
    return S;
  }
};
