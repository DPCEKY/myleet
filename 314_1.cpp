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
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root == NULL)
      return res;
    std::unordered_map<TreeNode*, int> map;
    std::queue<std::pair<TreeNode*, int>> s;
    int leftmost_col = 0, rightmost_col = 0;
    s.push({root, 0});
    while(!s.empty()) {
      auto pair = s.front();
      s.pop();
      auto node = pair->left;
      auto col = pair->second;
      if(col > rightmost_col)
        rightmost_col = col;
      else if(col < leftmost_col)
        leftmost_col = col;
      map.emplace_back(node, col);
      if(node->left != NULL)
        s.push({node->left, col - 1});
      if(node->right != NULL)
        s.push({node->right, col + 1});
    }

    res.resize(rightmost_col - leftmost_col + 1);
    s.push({root, 0});
    while(!s.empty()) {
      auto pair = s.front();
      s.pop();
      auto node = pair->left;
      res[map[node] - leftmost_col].push_back(node->val);
      if(node->left != NULL)
        s.push({node->left, 0});
      if(node->right != NULL)
        s.push({node->right, 0});
    }
    return res;
  }
};

