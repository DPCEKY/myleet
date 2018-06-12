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
  int minMeetingRooms(vector<Interval>& intervals) {
    std::sort(intervals.begin(), intervals.end(), 
              [](Interval a, Interval b) {
                return a.start < b.start;
              });

    auto it = intervals.begin();
    int res = 0;
    vector<Interval>& to_decide = {};
    while(true) {
      if(intervals.size() == 0)
        break;
      if(it + 1 == intervals.end()) {
        res++;
        intervals.clear();
        intervals.swap(to_decide);
        it = intervals.begin();
        continue;
      }

      if(it->end > (it + 1)->start) {
        to_decide.push_back(it + 1);
        intervals.erase(it + 1);
      }
      else
        it++;
    }

    return res;
  }
};
