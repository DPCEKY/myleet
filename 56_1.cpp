/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    std::map<int, int> map;
    for(const auto& i : intervals) {
      auto it = map.find(i.start);
      if(it != map.end()) {
        if(it->second >= i.end)
          continue;
        map.erase(it);
      }
        
      map.emplace(i.start, i.end);
    }
    
    vector<Interval> res;
    for(auto it = map.begin(); it != map.end(); ) {
      Interval item(it->first, it->second);
      do{
        it++;
        if(it != map.end()) {
          if(item.end >= it->first && item.end < it->second) {
            item.end = it->second;
          }
          else if(item.end >= it->second)
            continue;
          else
            break;
        }
      }while(it != map.end());
      res.push_back(item);
    }
    return res;
    
  }
};
