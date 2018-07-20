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
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if(s == NULL)
      return false;
    if(s->val == t->val) {
      if(validSub(s, t) == true)
        return true;
    }
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }

  bool validSub(TreeNode* s, TreeNode* t) {
    if(s == NULL && t == NULL)
      return true;
    else if(s == NULL && t != NULL || s != NULL && t == NULL)
      return false;
    else if(s->val != t->val)
      return false;

    return validSub(s->left, t->left) && validSub(s->right, t->right);
  }
};
