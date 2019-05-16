class Solution {
public:
  int totalFruit(vector<int>& tree) {
    std::unordered_map<int, int> baskets;
    int res = 0;
    int last_fruit = 0, last_fruit_count = 0;
    for(auto fruit : tree) {
      if(baskets.find(fruit) != baskets.end()) {
        baskets[fruit]++;
      }
      else if(baskets.size() < 2) {
        baskets[fruit] = 1;
      }
      else {
        int curr = accumulate(baskets);
        res = max(res, curr);
        baskets.clear();
        baskets.emplace(last_fruit, last_fruit_count);
        baskets[fruit] = 1;
      }
      
      if(fruit == last_fruit) {
        last_fruit_count++;
      }
      else {
        last_fruit = fruit;
        last_fruit_count = 1;
      }
    }
    return max(res, accumulate(baskets));
  }

  int accumulate(std::unordered_map<int, int>& baskets) {
    int curr = 0;
    for(auto it = baskets.begin(); it != baskets.end(); it++) {
      curr += it->second;
    }
    return curr;
  }
};
