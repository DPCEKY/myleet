class TrieNode {
public:
  TrieNode(char in = ' ') : is_word(false), val(in) {
    for(int i = 0; i < 26; i++) {
      next[i] = NULL;
    }
  }

  bool is_word;
  char val;
  *TrieNode next[26];
};

class Trie {
public:
    /** Initialize your data structure here. */
  Trie() {
    root = new TrieNode();
  }
    
    /** Inserts a word into the trie. */
  void insert(string word) {
    auto node = root;
    for(auto it : word) {
      if(node->next[it - 'a'] == NULL) {
        node->next[it - 'a'] = new TrieNode(it);
      }
      node = node->next[it - 'a'];
    }
    node->is_word = true;
  }
    
    /** Returns if the word is in the trie. */
  bool search(string word) {
    auto node = root;
    for(auto it : word) {
      if(node->next[it - 'a'] == NULL) {
        return false;
      }
      node = node->next[it - 'a'];
    }
    return node->is_word;
  }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    auto node = root;
    for(auto it : prefix) {
      if(node->next[it - 'a'] == NULL) {
        return false;
      }
      node = node->next[it - 'a'];
    }
    return true;
  }

private:
 *TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
