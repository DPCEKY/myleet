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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(root == NULL) {
      return res;
    }

    string s;
    s += to_string(root->val);

    auto left = binaryTreePaths(root->left);
    auto right = binaryTreePaths(root->right);

    if(root->left == NULL && root->right == NULL) {
      res.push_back(s);
      return res;
    }
    
    while(!left.empty()) {
      res.push_back(s + "->" + left[0]);
      left.erase(left.begin());
    }

    while(!right.empty()) {
      res.push_back(s + "->" + right[0]);
      right.erase(right.begin());
    }

    return res;
  }

};

