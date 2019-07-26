class MyCalendarTwo {
public:
  MyCalendarTwo() {
    
  }

  bool book(int start, int end) {
    if(!check(start, end, 1)) {
      return false;
    }
    insertToMaps(start, end);
    return true;
  }

  bool check(int start, int end, int map_num) {
    if(map_num == 1) {
      auto itr = map1.lower_bound(start);
      while(itr != map1.end() && end > itr->first) {
        if(!check(itr->first, min(end, itr->second), 2)) {
          return false;
        }
        if(end <= itr->second) {
          break;
        }
        else {
          start = itr->second;
          itr++;
        }
      }
      return true;
    }
    else {
      auto itr = map2.lower_bound(start);
      if(itr != map2.end() && end > itr->first) {
        return false;
      }
      return true;
    }
  }

  void insertToMaps(int start, int end) {
    auto itr = map1.lower_bound(start);
    if(map1.empty()) {
      map1[start] = end;
      return;
    }
    auto prev_itr = prev(itr);
    if(itr != map1.begin() && prev_itr->second >= start) {
      if(prev_itr->second > start) {
        map2[start] = min(end, prev_itr->second);
      }
      start = prev_itr->first;
      prev_itr->second = max(end, prev_itr->second);
      end = prev_itr->second;
    }
    else {
      if(end < itr->first) {
        map1[start] = end;
        return;
      }
      else if(end == itr->first) {
        map1[start] = itr->second;
        map1.erase(itr);
        return;
      }
      else {
        map2[itr->first] = min(end, itr->second);
        end = max(itr->second, end);
        itr++;
        map1.erase(prev(itr));
      }
    }

    while(itr != map1.end() && end >= itr->first) {
      if(end == itr->first) {
        prev_itr = prev(itr);
        prev_itr->second = itr->second;
        map1.erase(itr);
        break;
      }
      else {
        if(end <= itr->second) {
          map2[itr->first] = itr->second;
          map1[start] = itr->second;
          map1.erase(itr);
          break;
        }
        else {
          map2[itr->first] = itr->second;
          itr++;
        }
      }
    }
  }

private:
  std::map<int, int> map1;
  std::map<int, int> map2;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */


