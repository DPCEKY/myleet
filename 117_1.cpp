/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
  void connect(TreeLinkNode *root) {
    if(root == NULL)
      return;

    std::queue<TreeLinkNode*> q;
    TreeLinkNode dum(INT_MAX);
    q.push(root);
    q.push(&dum);
    TreeLinkNode* pre = NULL;

    while(!q.empty()) {
      auto node = q.front();
      q.pop();
      if(node->val == INT_MAX) {
        if(q.empty())
          break;
        pre = NULL;
        q.push(&dum);
      }
      
      if(pre == NULL)
        pre = node;
      else {
        pre->next = node;
        pre = node;
      }
      if(node->left != NULL)
        q.push(node->left);
      if(node->right != NULL)
        q.push(node->right);
    }

  }
};
