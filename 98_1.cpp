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
  bool isValidBST(TreeNode* root) {
    if(root == NULL)
      return true;
    std::stack<TreeNode*> stack;
    TreeNode* pre = NULL;

    while(root != NULL || !stack.empty()) {
      while(root != NULL) {
        stack.push(root);
        root = root->left;
      }

      if(!stack.empty()) {
        root = stack.top();
        if(pre != NULL && root->val <= pre->val)
          return false;
        pre = root;
        root = root->right;
        stack.pop();
      }
    }

    return true;

  }
};
