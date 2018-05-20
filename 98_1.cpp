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
    vector<int> tree;
    std::stack<TreeNode*> stack;

    while(root != NULL || !stack.empty()) {
      while(root != NULL) {
        stack.push(root);
        root = root->left;
      }

      if(!stack.empty()) {
        root = stack.top();
        tree.push_back(root->val);
        root = root->right;
        stack.pop();
      }
    }

    for(int i = 0; i < tree.size() - 1; i++) {
      if(tree[i] >= tree[i + 1])
        return false;
    }
    return true;

  }
};
