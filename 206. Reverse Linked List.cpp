//Phoenix_RK


/**

https://leetcode.com/problems/reverse-linked-list/

Reverse a singly linked list.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode *res=NULL;
    ListNode *rev(ListNode* head)
    {
              
        if(head==NULL)
            return NULL;

        if(head->next==NULL)
        {
            res=head;
            return head;
        }
     
          ListNode* red= rev(head->next);
          red->next= head;
          head->next=NULL;

          return head;
      }
    
    ListNode* reverseList(ListNode* head) {
    
        rev(head);
        return res;
        
        
    }
};


