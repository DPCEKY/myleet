class Solution {
public:
  int romanToInt(string s) {
    std::map<char, unsigned int> map;
    map.emplace('I', 1);
    map.emplace('V', 5);
    map.emplace('X', 10);
    map.emplace('L', 50);
    map.emplace('C', 100);
    map.emplace('D', 500);
    map.emplace('M', 1000);

    unsigned int sum = 0;
    for(int i = 0; i < s.size(); i++) {
      if(i+1 >= s.size()) {
        sum += map[ s[i] ];
      }
      else {
        if(map[s[i]] < map[s[i+1]]) {
          sum += map[ s[i+1] ] - map[ s[i] ];
          i++;
        }
        else {
          sum += map[ s[i] ];
        }
      }
    }
    
    return sum;

  }
};
