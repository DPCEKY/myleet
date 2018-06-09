class Trie {
public:
    /** Initialize your data structure here. */
  Trie() {
    
  }
    
    /** Inserts a word into the trie. */
  void insert(string word) {
    for(int i = 0; i < word.size(); i++) {
      if(map.find(word.substr(0, i + 1)) == map.end()) {
        map.insert({word.substr(0, i + 1), word});
      }
    }
    map[word] = word;
  }
    
    /** Returns if the word is in the trie. */
  bool search(string word) {
    return (map.find(word) != map.end()) && (map[word] == word);
  }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    return map.find(prefix) != map.end();
  }
private:
  std::unordered_map<std::string, std::string> map;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

