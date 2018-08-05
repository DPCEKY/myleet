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
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    calDepth(root, 0);
    while(true) {
      if(root->left == NULL && root->right == NULL)
        return root;
      if(root->left == NULL)
        root = root->right;
      else if(root->right == NULL)
        root = root->left;
      else {
        if(map[root->left->val] == map[root->right->val])
          return root;
        else if(map[root->left->val] > map[root->right->val])
          root = root->left;
        else
          root = root->right;
      }
    }
  }

  int calDepth(TreeNode* root, int depth) {
    if(root == NULL)
      return 0;
    else if(root->left == NULL && root->right == NULL) {
      map.emplace(root->val, depth);
      return depth;
    }
    int left = calDepth(root->left, depth + 1);
    int right = calDepth(root->right, depth + 1);
    map.emplace(root->val, max(left, right));
    return max(left, right);
  }
private:
  std::unordered_map<int, int> map;
};
