class Solution {
public:
  string toGoatLatin(string S) {
    if(S.empty())
      return S;
    string res;
    std::unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int space = -1;
    string end = "a";
    while(true) {
      auto pos = S.find_first_of(' ', space + 1);
      if(pos == std::string::npos)
        break;
      auto word = S.substr(space + 1, pos - space - 1);
      if(set.find(S[space + 1]) != set.end()) {
        word += "ma";
      }
      else {
        word = word.substr(1) + word[0] + "ma";
      }
      word += end;
      res += word + " ";
      end += "a";
      space = pos;
    }
    auto word = S.substr(space + 1);
    if(set.find(S[space + 1]) != set.end()) {
      word += "ma";
    }
    else {
      word = word.substr(1) + word[0] + "ma";
    }
    word += end;
    res += word;
    return res;
  }
};

