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
    if(head == NULL || head ->next == NULL) {
      return true;
    }

    vector<int> list;
    auto tail = head;
    while(head != NULL) {
      list.push_back(head->val);
      head = head->next;
    }
    head = reverse(tail);
    
    int i = 0;
    while(head != NULL) {
      if(head->val != list[i])
        return false;
      head = head->next;
      i++;
    }
    return true;
  }

 ListNode* reverse(ListNode* head) {
    if(head == NULL || head->next == NULL) {
      return head;
    }

    auto sec = head->next;
    auto tail = reverse(head->next);
    sec->next = head;
    head->next = NULL;
    return tail;
  }
};
