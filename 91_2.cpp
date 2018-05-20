class Solution {
public:
  int numDecodings(string s) {
    if(s.size() < 2)
      return s[0] == '0' ? 0 : s.size();

    vector<int> map;
    map.push_back(1);
    if(s[0] == '1' || (s[0] == '2' && s[1] <= '6'))
      if(s[1] == '0')
        map.push_back(1);
      else
        map.push_back(2);
    else if(s[0] != '0' && s[1] != '0')
      map.push_back(1);
    else
      return 0;

    for(int i = 2; i < s.size(); i++) {
      if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
        if(s[i] != '0')
          map.push_back(map[i - 1] + map[i - 2]);
        else
          map.push_back(map[i - 2]);
      }
      else if(s[i] != '0')
        map.push_back(map[i - 1]);
      else
        return 0;
    }

    return map.back();
  }
};
