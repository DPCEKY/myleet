class Solution {
public:
  std::unordered_map<char, char> table {
    {'2', 'a'}, {'3', 'd'},
    {'4', 'g'}, {'5', 'j'}, {'6', 'm'}, 
    {'7', 'p'}, {'8', 't'}, {'9', 'w'},
    {'9' + 1, 'z' + 1}
  };

  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if(digits.empty())
      return result;
    else if(digits.size() == 1) {
      for(int i = table[digits[0] + 1] - table[digits[0]] - 1; i >= 0; i--) {
        char key = table[digits[0]] + i;
        string res({key});
        result.push_back(res);
      }
    }

    vector<string> rest = letterCombinations(digits.substr(1));
    for(int i = table[digits[0] + 1] - table[digits[0]] - 1; i >= 0; i--) {
      for(auto it : rest) {
        char key = table[digits[0]] + i;
        string res = static_cast<char>(key) + it;
        result.push_back(res);
      
      }
    }
    return result;
  }

};

