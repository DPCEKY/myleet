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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    auto left = min(p->val, q->val);
    auto right = max(p->val, q->val);

    while(root->val < left || root->val > right) {
      if(root->val < left)
        root = root->right;
      else
        root = root->left;
    }

    return root;
  }
};
