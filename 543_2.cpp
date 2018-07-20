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
  int max;
  int diameterOfBinaryTree(TreeNode* root) {
    max = 0;
    maxDep(root);
    return max;
  }

  int maxDep(TreeNode* node) {
    if(node == NULL)
      return -1;

    int left = 1 + maxDep(node->left);
    int right = 1 + maxDep(node->right);
    max = max(left + right, max);
    return max(left, right);
  }
};

