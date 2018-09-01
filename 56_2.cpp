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
    vector<Interval> res;
    std::sort(intervals.begin(), intervals.end(), [](Interval i, Interval j){
      return i.start < j.start;
});
    for(auto i : intervals) {
      if(res.empty())
        res.push_back(i);
      else {
        auto prev = res.back();
        if(prev.end >= i.start) {
          if(prev.end >= i.end)
            continue;
          res.back().end = i.end;
        }
        else
          res.push_back(i);
      }
    }
    return res;
  }
};

