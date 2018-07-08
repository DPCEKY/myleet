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
    if(p->val == root->val)
      return p->right;
    if(p->val > root->val)
      return inorderSuccessor(root->right, p);
    return findSucc(root->left, p, root);
  }
  TreeNode* findSucc(TreeNode* curr, TreeNode* p, TreeNode* succ) {
    if(p->val == curr->val) {
      if(curr->right != NULL) {
        auto answer = curr->right;
        while(answer->left != NULL)
          answer = answer->left;
        return answer;
      }
      return succ;
    }
    if(p->val < curr->val) {
      return findSucc(curr->left, p, curr);
    }
    return findSucc(curr->right, p, succ);
  }
};

