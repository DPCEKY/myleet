class Solution {
public:
  int removeStones(vector<vector<int>>& stones) {
    std::unordered_map<int, int> map;
    
    for(int i = 0; i < stones.size(); i++) {
      map.insert({stones[i][0], stones[i][0]});
      map.insert({20000 + stones[i][1], 20000 + stones[i][1]});
    }

    int count = map.size();
    for(int i = 0; i < stones.size(); i++) {
      count -= unio(map, stones[i][0], 20000 + stones[i][1]);
    }

    return stones.size() - count;
  }

  int find(std::unordered_map<int, int>& map, int i) {
    if(map[i] == i)
      return i;
    map[i] = find(map, map[i]);
    return map[i];
  }

  int unio(std::unordered_map<int, int>& map, int i, int j) {
    int i0 = find(map, i);
    int j0 = find(map, j);
    if(i0 != j0) {
      map[i0] = j0;
      return 1;
    }
    else {
      return 0;
    }
  }
};
