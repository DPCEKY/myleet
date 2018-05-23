class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    std::unordered_set<string> set;
    for(auto it : wordList) {
      set.insert(it);
    }
    if(set.find(endWord) == set.end())
      return 0;

    int res = 2;
    vector<string> v, bfs;
    v.push_back(beginWord);
    do{
      while(!v.empty()) {
        auto str = v.back();
        v.pop_back();
        for(int i = 0; i < str.size(); i++) {
          auto backup = str;
          for(int j = 0; j < 25; j++) {
            str[i] = 'a' + j;
            if(set.find(str) != set.end()) {
              if(str == endWord)
                return res;
              bfs.push_back(str);
              set.erase(str);
            }
          }
          str = backup;
        }
      }
      if(bfs.empty())
        return 0;
      res++;
      v.swap(bfs);
    } while(!v.empty());

  }
};

