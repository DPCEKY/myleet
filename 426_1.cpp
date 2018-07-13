/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
  Node* treeToDoublyList(Node* root) {
    if(root == NULL)
      return NULL;
    Node* head = NULL;
    std::stack<Node*> s;
    std::queue<Node*> q;
    Node* node = root;
    while(!s.empty() || node != NULL) {
      while(node != NULL) {
        s.push(node);
        node = node->left;
      }
      node = s.top();
      s.pop();
      q.push(node);
      node = node->right;
    }
    
    head = q.front();
    Node* prev = NULL;
    while(!q.empty()) {
      node = q.front();
      q.pop();
      if(prev != NULL) {
        node->left = prev;
      }
      if(!q.empty())
        node->right = q.front();
      else
        node->right = head;
      prev = node;
    }
    head->left = prev;
    return head;
  }
};
