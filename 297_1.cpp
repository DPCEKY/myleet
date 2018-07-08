/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if(root == NULL)
      return "";
    std::queue<TreeNode*> q;
    std::string res;
    res = to_string(root->val) + "x";
    q.push(root);
    while(!q.empty()) {
      auto node = q.front();
      q.pop();
      if(node->left != NULL) {
        q.push(node->left);
        res = res + to_string(node->left->val) + "x";
      }
      else
        res.push_back(' ');
      if(node->right != NULL) {
        q.push(node->right);
        res = res + to_string(node->right->val) + "x";
      }
      else
        res.push_back(' ');
    }
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if(data.empty())
      return NULL;
    auto root = new TreeNode(0);
    std::queue<TreeNode*> q;
    q.push(root);
    int ptr = 0, child = next_len(data, 0) + 1;
    while(child < data.size()) {
      auto node = q.front();
      q.pop();
      
      auto ptr_len = next_len(data, ptr);
      node->val = stoi(data.substr(ptr, ptr_len));
      ptr = ptr + ptr_len + 1;
      
      if(data[child] != ' ') {
        auto left = new TreeNode(0);
        
        auto child_len = next_len(data, child);
        left->val = stoi(data.substr(child, child_len));

        child = child + child_len + 1;
        
        node->left = left;
        left->left = NULL;
        left->right = NULL;
        q.push(left);
      }
      else {
        node->left = NULL;
        child++;
      }

      if(data[child] != ' ') {
        auto right = new TreeNode(0);

        auto child_len = next_len(data, child);
        right->val = stoi(data.substr(child, child_len));
        child = child + child_len + 1;
        
        node->right = right;
        right->left = NULL;
        right->right = NULL;
        q.push(right);
      }
      else {
        node->right = NULL;
        child++;
      }
      
      while(data[ptr] == ' ')
        ptr++;
    }
    return root;
  }
  
  int next_len(std::string str, int pos) {
    int length = 0;
    while(str[length + pos] != 'x')
      length++;
    return length;
  }
  
  int stoi(std::string in) {
    int res = 0;
    int i = 0;
    if(in[0] == '-')
      i = 1;
    for(; i < in.size(); i++) {
      if(in[0] == '-')
        res = res * 10 - (in[i] - '0');
      else
        res = res * 10 + in[i] - '0';
    }
    return res;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


