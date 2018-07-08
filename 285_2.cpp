/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    vector<TreeNode*> s;
    TreeNode* node = root;
    bool found_p = false;
    while(node != NULL || !s.empty()) {
      while(node != NULL) {
        s.push_back(node);
        node = node->left;
      }
      node = s.back();
      s.pop_back();
      if(found_p == true)
        return node;
      if(node->val == p->val) 
        found_p = true;
      node = node->right;
    }
    return NULL;
  }
};
