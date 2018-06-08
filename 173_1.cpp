/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    while(root != NULL) {
      q.push_back(root);
      root = root->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !q.empty();
  }

  /** @return the next smallest number */
  int next() {
    auto node = q.back();
    q.pop_back();
    if(node->right != NULL) {
      auto to_push = node->right;
      while(to_push != NULL) {
        q.push_back(to_push);
        to_push = to_push->left;
      }
    }
    return node->val;
  }
private:
  vector<TreeNode*> q;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
