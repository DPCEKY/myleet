class LRUCache {
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    cur_size = 0;
  }
  
  int get(int key) {
    if(map.find(key) == map.end()) {
      return -1;
    }
    auto it = map[key];
    int res = it->second;
    list.erase(it);
    list.emplace_front(key, res);
    map[key] = list.begin();
    return res;
  }
  
  void put(int key, int value) {
    if(map.find(key) == map.end()) {
      list.emplace_front(key, value);
      map.emplace(key, list.begin());
      cur_size++;
    }
    else {
      auto it = map[key];
      list.erase(it);
      list.emplace_front(key, value);
      map[key] = list.begin();
    }
    if(cur_size > capacity) {
      list.erase(list.rbegin());
      cur_size--;
    }
  }
private:
  std::unordered_map<int, list<int>::iterator> map;
  std::list<std::pair<int, int>> list;
  int capacity;
  int cur_size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
