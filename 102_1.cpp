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
  vector<vector<int>> levelOrder(TreeNode* root) {
    std::queue<TreeNode*> q;
    vector<vector<int>> res;
    vector<int> level;

    if(root == NULL)
      return res;
    
    TreeNode n(INT_MAX);
    q.push(root);
    q.push(&n);

    while(!q.empty()) {
      auto node = q.front();
      q.pop();
      if(node->val == INT_MAX) {
        res.push_back(level);
        level.clear();
        if(q.empty())
          break;
        q.push(&n);
        continue;
      }
      level.push_back(node->val);
      if(node->left != NULL)
        q.push(node->left);
      if(node->right != NULL)
        q.push(node->right);
    }
    return res;

  }
};

