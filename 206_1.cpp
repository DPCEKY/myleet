/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL) {
      return head;
    }

    auto pre = head->next;
    auto in = head;
    ListNode* pos = NULL;
    while(pre->next != NULL) {
      in->next = pos;
      pos = in;
      in = pre;
      pre = pre->next;
    }
    
    in->next = pos;
    pre->next = in;
    return pre;
  }
};
