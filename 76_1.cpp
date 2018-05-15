class Solution {
public:
  string minWindow(string s, string t) {
    if(s.empty() || t.empty())
      return "";

    std::unordered_map<char, int> map;
    for(auto it : t) {
      if(map.find(it) == map.end())
        map.emplace(it, -1);
      else
        map[it]--;
    }
    
    int to_find = map.size();
    int start = 0;
    int min_start, min_end;
    int min_length = INT_MAX;

    for(int end = 0; end < s.size(); end++) {
      if(map.find(s[end]) != map.end()) {
        map[s[end]]++;
        if(map[s[end]] == 0)
          to_find--;
      }
      
      while(to_find == 0) {
        int length = end - start + 1;
        if(length < min_length) {
          min_start = start;
          min_length = length;
        }

        if(map.find(s[start]) != map.end()) {
          map[s[start]]--;
          if(map[s[start]] < 0)
            to_find++;
        }
        start++;
      }

    }

    if(min_length != INT_MAX) {
      return s.substr(min_start, min_length);
    }
    else
      return "";

  }
};

