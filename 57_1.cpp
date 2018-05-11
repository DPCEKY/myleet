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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    if(intervals.empty()) {
      intervals.push_back(newInterval);
      return intervals;
    }
    
    auto erase_start = intervals.begin();
    auto erase_end = intervals.begin();
    Interval to_insert;
    for(auto it = intervals.begin(); it != intervals.end(); it++) {
      if(it + 1 == intervals.end() && it->end < newInterval.start) {
        intervals.push_back(newInterval);
        return intervals;
      }

      if(it->start >= newInterval.start) {
        erase_start = it;
        to_insert.start = newInterval.start;
        if(it->end >= newInterval.end) {
          if(it->start > newInterval.end) {
            intervals.insert(it, newInterval);
            return intervals;
          }
          erase_end = it + 1;
          to_insert.end = it->end;
        }
        while(it->end < newInterval.end) {
          it++;
          if(it == intervals.end() || it->start > newInterval.end) {
            erase_end = it;
            to_insert.end = newInterval.end;
            break;
          }
          else if(it->end >= newInterval.end) {
            erase_end = it + 1;
            to_insert.end = it->end;
            break;
          }
        }
        break;
      }
      else if(it->end >= newInterval.start) {
        erase_start = it;
        to_insert.start = it->start;
        if(it->end >= newInterval.end) {
          return intervals;
        }
        while(it->end < newInterval.end) {
          it++;
          if(it == intervals.end() || it->start > newInterval.end) {
            erase_end = it;
            to_insert.end = newInterval.end;
            break;
          }
          else if(it->end >= newInterval.end) {
            erase_end = it + 1;
            to_insert.end = it->end;
            break;
          }
        }
        break;
      }  
    }
    auto it = intervals.erase(erase_start, erase_end);
    intervals.insert(it, to_insert);
    return intervals;
  }
};

