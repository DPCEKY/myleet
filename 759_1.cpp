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
  vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
    vecotr<Interval> res;
    if(schedule.empty())
      return res;
    int N = schedule.size();
    auto all_time = mergeAll(schedule, 0, N - 1);
    if(!all_time.empty()) {
      auto head = all_time[0];
      for(int i = 1; i < all_time.size(); i++) {
        auto tail = all_time[i];
        res.push_back(new Interval(head.end, tail.start));
        head = tail;
      }
    }
    return res;
  }

  vector<Interval> mergeAll(vector<vector<Interval>>& schedule, int s, int e) {
    if(s == e)
      return schedule[s];
    else if(s + 1 == e)
      return merge2FreeTime(schedule[s], schedule[e]);
    auto left = mergeAll(shcedule, s, (s + e) / 2);
    auto right = nergeAll(schedule, (s + e) / 2 + 1, e);
    return merge2FreeTime(left, right);
  }

  vector<Interval> merge2FreeTime(vector<Interval>& a, vector<Iterval>& b) {
    if(a.empty())
      return b;
    else if(b.empty())
      return a;
    vector<Interval> res;
    int i = 0; j = 0;
    for(i = 0, j = 0; i < a.size() && j < b.size(); ) {
      if(a[i].end < b[j].start) {
        res.push_back(a[i++]);
      }
      else if(b[j].end < a[i].start) {
        res.push_back(b[j++]);
      }
      else {
        int start = min(a[i].start, b[j].start);
        int end = max(a[i].end, b[j].end);
        res.push_back(new Interval(start, end));
        i++; 
        j++;
      }
    }
    while(i < a.size()) {
      res.push_back(a[i++]);
    }
    while(j < b.size()) {
      res.push_back(b[j++]);
    }
    return res;
  }
};













