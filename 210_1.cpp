class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> res;
    if(numCourses <= 0)
      return res;

    vector<int> indegree;
    vector<vector<int>> adjlist;
    std::queue<int> next;
    indegree.resize(numCourses);
    adjlist.resize(numCourses);

    for(auto pair : prerequisites) {
      auto pre = pair.second;
      auto pos = pair.first;
      indegree[pos]++;
      adjlist[pre].push_back(pos);
    }
    for(auto it : indegree) {
      if(it == 0)
        next.push(it);
    }

    while(!next.empty()) {
      auto course = next.pop();
      res.push_back(course);
      for(auto it : adjlist[course]) {
        indegree[it]--;
        if(indegree[it] == 0) {
          next.push(it);
        }
      }
      adjlist[course].clear();
    }
    
    if(res.size() != numCourses)
      return res.clear();
    return res;
  }
};
