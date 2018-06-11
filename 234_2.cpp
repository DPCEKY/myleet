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
  bool isPalindrome(ListNode* head) {
    if(head == NULL || head->next == NULL) {
      return true;
    }
    
    ListNode* half = head, full = head;
    while(full->next != NULL && full->next->next != NULL) {
      full = full->next->next;
      half = half->next;
    }

    half = reverse(half->next);
    
    while(half != NULL) {
      if(half->val != head->val)
        return false;
      head = head->next;
      half = half->next;
    }
    return true;
  }

  ListNode* reverse(ListNode* head) {
    if(head == NULL || head->next == NULL)
      return head;

    ListNode* pre = head->next, in = head, pos = NULL;
    while(pre != NULL) {
      in->next = pos;
      pos = in;
      in = pre;
      pre = pre->next;
    }
    in->next = pos;

    return in;    
  }
};
