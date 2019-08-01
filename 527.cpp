class Solution {
public:
  vector<string> wordsAbbreviation(vector<string>& dict) {
    vector<string> res(dict.size());
    std::unordered_map<string, int> orders;
    std::unordered_map<int, std::set<string>> dicts;
    
    std::cout << "dicts.size() = " + dicts.size() << "???" << std::endl;
    
    int i = 0;
    for(auto& word : dict) {
      orders[word] = i++;
      
      if(dicts.count(word.size()) == 1) {
        dicts[word.size()].insert(word);
      }
      else {
        std::set<string> myset;
        myset.insert(word);
        dicts[word.size()] = myset;
      }
      std::cout << "i = " << i << ", dicts.size() = " + dicts.size() << "???" << std::endl;

    }
    std::cout << "dicts.size() = " + dicts.size() << "???" << std::endl;

    
    
    for(auto& mydict_pair : dicts) {
      auto& mydict = mydict_pair.second;
      for(auto it = mydict.begin(); it != mydict.end(); it++) {
        if(it == mydict.begin() || std::next(it) == mydict.end()) {
          if(mydict.size() == 1) {
            res.push_back(abbreivate(*it));
            return res;
          }
          else {
            auto word = it == mydict.begin() ? 
                        abbreivate(*it, *std::next(it)) : 
                        abbreivate(*it, *std::prev(it));
            res[orders[*it]] = word;
          }
        }
        else {
          auto word = abbreivate(*it, *std::prev(it), *std::next(it));
          res[orders[*it]] = word;
        }
      }
    }
    return res;
  }

  string abbreivate(string word) {
    std::cout << "word = " + word << std::endl;
    
    if(word.size() <= 3) {
      return word;
    }
    else {
      return word[0] + std::to_string(word.size() - 2) + word.back();
    }
  }

  string abbreivate(string word, string word1) {
    std::cout << "word = " + word << ", word1 = " << word1 << std::endl;
    
    if(word.size() != word1.size()) {
      return abbreivate(word);
    }
    for(int i = 0; i < word.size(); i++) {
      if(word1[i] != word[i]) {
        return word.substr(0, i - 1) + abbreivate(word.substr(i - 1));
      }
    }
    return word;
  }

  string abbreivate(string word, string word1, string word2) {
    std::cout << "word = " + word << ", word1 = " << word1 << ", word2 = " << word2 << std::endl;
    
    if(word.size() != word1.size()) {
      return abbreivate(word, word2);
    }
    else if(word.size() != word2.size()) {
      return abbreivate(word, word1);
    }

    for(int i = 0; i < word.size(); i++) {
      if(word[i] != word1[i] && word[i] == word2[i]) {
        return abbreivate(word, word2);
      }
      else if(word[i] == word1[i] && word[i] != word2[i]) {
        return abbreivate(word, word1);
      }
      else if(word[i] != word1[i] && word[i] != word2[i]) {
        return word.substr(0, i - 1) + abbreivate(word.substr(i - 1));
      }
    }

    std::cout << "FETAL: NOT ALLOWED TO BE HERE!" << std::endl;
    return word;
  }
};





















