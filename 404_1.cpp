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
  int sumOfLeftLeaves(TreeNode* root) {
    if(root == NULL || (root-> left == NULL && root -> right == NULL))
      return 0;
    return leftSum(root->left) + sumOfLeftLeaves(root->right);
  }
  
  int leftSum(TreeNode* node) {
    if(node == NULL)
      return 0;
    return node->val + leftSum(root->left) + sumOfLeftLeaves(root->right);
  }
};
