class RandomizedSet {
public:
    /** Initialize your data structure here. */
  RandomizedSet() {
    size = 0;
  }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    // print("insert", val);
    if(map.find(val) == map.end()) {
      table.push_back({val, true});
      map.emplace(val, table.size() - 1);
      size++;
      return true;
    }
    else {
      auto it = map[val];
      if(table[it].second == false) {
        table[it].second = true;
        size++;
        return true;
      }
    }
    return false;
  }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    // print("remove", val);
    if(map.find(val) != map.end()) {
      auto it = map[val];
      // cout << "prepare removing."<< endl;
      // cout << "wrong: val = " << it->first << ", bool = " << it->second << endl;
      // cout << "right: val = " << *it.first << ", bool = " << *it.second << endl;
      if(table[it].second == true) {
        // cout << "removing!" << endl;
        table[it].second = false;
        size--;
        // print("removed msg");
        return true;
      }
    }
    return false;
  }
    
    /** Get a random element from the set. */
  int getRandom() {
    // print("getRandom");
    if(size == 0)
      return -1;
    auto seed = rand() % table.size();
    std::pair<int, bool> it;
    while(true) {
      it = table[seed];
      if(it.second == true)
        break;
      seed = (seed + 1) % table.size();
    }
    return it.first;
  }
  
  // void print(string msg, int val = 0) {
  //   cout << "[debug msg]: " << msg;
  //   if(val != 0)
  //     cout << " " << val;
  //   cout << endl;
  //   for(int i = 0; i < table.size(); i++) {
  //     cout << "table[" << i << "] = " << table[i].first << ", v = " << table[i].second << endl;
  //   }
  // }
private:
  std::unordered_map<int, int> map;
  std::vector<std::pair<int, bool>> table;
  int size;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

