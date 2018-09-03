class ZigzagIterator {
public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    if(v1.size() != 0)
      q.push({v1.begin(), v1.end()});
    if(v2.size() != 0)
      q.push({v2.begin(), v2.end()});
  }

  int next() {
    auto pair = q.front();
    auto it = (pair.first);
    auto endIt = pair.second;
    q.pop();
    int res = *it;
    it++;
    if(it != endIt)
      q.push({it, endIt});
    return res;
  }

  bool hasNext() {
    return !q.empty();
  }
private:
  std::queue<std::pair<vector<int>::iterator, vector<int>::iterator>> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

