class Solution {
public:
  vector<string> wordsAbbreviation(vector<string>& dict) {
    std::vector<string> res;
    std::vector<int> indexes;
    std::unordered_map<string, vector<int>> dups, new_dups;

    for(int i = 0; i < dict.size(); i++) {
      res.push_back(abbrev(dict[i], 0));
      indexes.push_back(0);
      dups[res.back()].push_back(i);
      // std::cout << "res.back() = " << res.back() << std::endl;
    }

    bool proceed = true;
    while(proceed) {
      proceed = false;
      for(auto& pair : dups) {
        if(pair.second.size() > 1) {
          // std::cout << "pair.first = " << pair.first << std::endl;
          
          proceed = true;
          for(auto& i : pair.second) {
            res[i] = abbrev(dict[i], ++indexes[i]);
            new_dups[res[i]].push_back(i);
          }
        }
      }
      dups.clear();
      dups.swap(new_dups);
    }

    return res;
  }

  string abbrev(string word, int index) {

    if(index + 3 >= word.size()) {
      return word;
    }
    
    return word.substr(0, index + 1) + std::to_string(word.size() - index - 2) + word.back();
  }
};

