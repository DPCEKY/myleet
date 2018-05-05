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
  ListNode* reverseKGroup(ListNode* head, int k) {
    unsigned int length = 0;
    ListNode* p = head;
    while(length < k) {
      if(p != NULL) {
        p = p->next;
        length++;
      }
      else
        break;
    }
    
    if(length < k || k == 1)
      return head;
    
    auto res = reverseKGroup(p, k);
    ListNode* first = head;
    ListNode* next = first->next;
    ListNode* next_two = next->next;
    
    
    for(int i = 0; i < k - 1; i++) {
      next->next = first;
      first = next;
      next = next_two;
      if(next_two != NULL)
        next_two = next_two->next;
    }
    head->next = res;
    return first;   
    
  }
};

