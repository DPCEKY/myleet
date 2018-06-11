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
    if(root == NULL)
      return NULL;

    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    bool p_found = false, q_found = false;
    if(left != NULL) {
      if(left->val == p->val)
        p_found = true;
      else if(left->val == q->val)
        q_found = true;
      else
        return left;
    }
    
    if(right != NULL) {
      if(right->val == p->val)
        p_found = true;
      else if(right->val == q->val)
        q_found = true;
      else
        return right;
    }

    bool root_found = p->val == root->val || q->val == root->val;
    
    switch(root_found * 4 + p_found * 2 + q_found) {
      case 0: return NULL;
      case 1: return q;
      case 2: return p;
      case 4: return root;
      case 3: return root;
      case 5: return root;
      case 6: return root;
    } 
  }
};

