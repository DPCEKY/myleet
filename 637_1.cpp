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
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    if(root == NULL)
      return res;
    std::queue<TreeNode*> q;
    TreeNode* dumb = new TreeNode(-1);
    q.push(root);
    q.push(dumb);
    int level_sum = 0, level_count = 0;
    while(!q.empty()) {
      auto node = q.front();
      q.pop();
      if(node->val != -1) {
        level_sum += node->val;
        level_count++;
        if(node->left != NULL)
          q.push(node->left);
        if(node->right != NULL)
          q.push(node->right);
      }
      else {
        if(!q.empty())
          q.push(dumb);
        res.push_back(level_sum / level_count);
        level_sum = 0;
        level_count = 0;
      }
    }
   return res;
  }
};
