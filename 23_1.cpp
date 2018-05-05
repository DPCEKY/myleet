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
  ListNode* merge(ListNode* a, ListNode* b) {
    ListNode* result = NULL;
    ListNode* last = result;
    while(a != NULL && b != NULL) {
      ListNode res;
      if(a->val <= b->val) {
        res.val = a->val;
        a = a->next;
      }
      else {
        res.val = b->val;
        b = b->next;
      }

      if(last != NULL) {
        last->next = &res;
        last = &res;
      }
      else {
        result = &res;
        last = result;
      }
    }

    while(a != NULL) {
      ListNode res;
      res.val = a->val;
      last->next = &res;
      last = &res;
    }

    while(b != NULL) {
      ListNode res;
      res.val = b->val;
      last->next = &res;
      last = &res;
    }
    return result;
  }

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty())
      return NULL;
    else if(lists.size() == 1)
      return lists[0];

    ListNode* res = lists.back();
    for(int i = lists.size() - 1; i > 0; i--) {
      res = merge(lists[i - 1], res);
    }
    return res;

  }
};

