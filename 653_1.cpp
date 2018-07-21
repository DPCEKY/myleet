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
  bool findTarget(TreeNode* root, int k) {
    if(root == NULL)
      return false;
    std::unordered_set<int> set;
    std::stack<TreeNode*> stack;
    TreeNode* node = root;
    while(!stack.empty() || node != NULL) {
      while(node != NULL) {
        if(set.empty())
          set.insert(node->val);
        else if(set.find(k - node->val) != set.end())
          return true;
        else
          set.insert(node->val);
        
        if(node->right != NULL)
          stack.push(node->right);
        node = node->left;
      }
      if(!stack.empty()) {
        node = stack.top();
        stack.pop();
      }
    }
    return false;
  }
};

