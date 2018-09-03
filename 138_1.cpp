/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
// 1. pointer using ->
// 2. inserting: append first, redirect second
// 3. seperating: last node does not have grandchild
// 4. before return: check again with requirements: random could be NULL
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode* res;
    RandomListNode* origin = head;
    if(head == NULL)
      return NULL;
    // first round: copy and insert
    while(origin != NULL) {
      RandomListNode* node = new RandomListNode(origin->label);
      node->next = origin->next;
      origin->next = node;
      origin = node->next;
    }

    origin = head;
    //second round: copy random
    while(origin != NULL) {
      RandomListNode* node = origin->random;
      if(node == NULL) {
        origin = origin->next->next;
        continue;
      }
      node = node->next;
      origin->next->random = node;
      origin = origin->next->next;
    }

    origin = head;
    res = origin->next;
    //third round: seperate res and restore origin
    while(origin !=NULL) {
      RandomListNode* node = origin->next;
      origin->next = node->next;
      if(node->next == NULL)
        break;
      node->next = node->next->next;
      origin = origin->next;
    }
    return res;
  }
};

