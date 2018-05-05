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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty())
      return NULL;
    else if(lists.size() == 1)
      return lists[0];

    unsigned int back = lists.size() - 1;
    while(back != 0) {
      unsigned int front = 0;
      while(back > front) {
        ListNode* front_next = lists[front];
        if(front_next == NULL) {
          lists[front] = lists[back];
          front++;
          back--;
          continue;
        }
        
        ListNode* back_next = lists[back];
        if(back_next == NULL) {
          back--;
          continue;
        }

        ListNode* res;
        if(front_next->val <= back_next->val) {
          res = front_next;
          front_next = front_next->next;
        }
        else {
          res = back_next;
          back_next = back_next->next;
        }
        ListNode* last_node = res;

        while(front_next != NULL && back_next != NULL) {
          if(front_next->val <= back_next->val) {
            last_node->next = front_next;
            last_node = front_next;
            front_next = front_next->next;
          }
          else {
            last_node->next = back_next;
            last_node = back_next;
            back_next = back_next->next;
          }
        }
        
        while(front_next != NULL) {
          last_node->next = front_next;
          last_node = front_next;
          front_next = front_next->next;
        }

        while(back_next != NULL) {
          last_node->next = back_next;
          last_node = back_next;
          back_next = back_next->next;
        }
        
        lists[front] = res;
        front++;
        back--;

      }

    }
    return lists[0];
  }
};

