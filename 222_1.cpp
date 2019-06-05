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
  int countNodes(TreeNode* root) {
    int count = 0;
    countNode(root, count);
    return count;
  }

  void countNode(TreeNode* root, int& count) {
    if(root == NULL) {
      return;
    }
    count++;
    countNode(root->left, count);
    countNode(root->right, count);
  }
};
