class Trie {
public:
  Trie(char val = ' ', bool is_word = false) : val(val), is_word(is_word) {
    for(int i = 0; i < 26; i++) {
      next[i] = NULL;
    }
  }
  char val;
  Trie* next[26];
  bool is_word;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
  WordDictionary() {
    root = new Trie();
  }
    
    /** Adds a word into the data structure. */
  void addWord(string word) {
    auto node = root;
    for(int i = 0; i < word.size(); i++) {
      if(node->next[word[i] - 'a'] == NULL)
        node->next[word[i] - 'a'] = new Trie(word[i] - 'a');
      node = node->next[word[i] - 'a'];
    }
    node->is_word = true;
  }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) {
    return search(word, root);
  }

  bool search(string word, Trie* node) {
    if(word.empty())
      return node->is_word;
    for(int i = 0; i < word.size(); i++) {
      if(word[i] != '.' && node->next[word[i] - 'a'] == NULL)
        return false;
      else if(word[i] == '.') {
        for(int j = 0; j < 26; j++) {
          if(node->next[j] != NULL) {
            // cout << "word == " << word << ", node->next[j] = " << (char)(j + 'a') << endl;
            auto res = search(word.substr(i + 1), node->next[j]);
            if(res == true)
              return true;
          }
        }
        return false;
      }
      node = node->next[word[i] - 'a'];
    }
    return node->is_word;
  }
private:
  Trie* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

