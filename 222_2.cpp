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
    if(root == NULL)
      return 0;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    int dl = 1, dr = 1;
    while(left != NULL) {
      left = left->left;
      dl++;
    }
    while(right != NULL) {
      right = right->right;
      dr++;
    }
    if(dl == dr) {
      return pow(2, dl) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
