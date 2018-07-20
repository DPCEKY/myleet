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
  int diameterOfBinaryTree(TreeNode* root) {
    if(root == NULL)
      return 0;
    int left = 1 + calLength(root->left);
    int right = 1 + calLength(root->right);
    auto left_child = diameterOfBinaryTree(root->left);
    auto right_child = diameterOfBinaryTree(root->right);
    auto child = max(left_child, right_child);
    retunr max(left + right, child);
  }

  int calLength(TreeNode* node) {
    if(node == NULL)
      return -1;
    if(node->left == NULL)
      return 1 + calLength(node->right);
    else if(node->right == NULL)
      return 1 + calLength(node->left);

    int left = 1 + calLength(node->left);
    int right = 1 + calLength(node->right);
    return max(left, rigth);
  }
};
