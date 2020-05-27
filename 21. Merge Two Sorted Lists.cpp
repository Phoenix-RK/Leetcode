//Phoenix_RK


/*

https://leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/


/**
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
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL && l2==NULL)
            return NULL;
        
        if(l2==NULL)
            return l1;
        
        if(l1==NULL)
            return l2;
        if(l1->val==l2->val)
        {
            ListNode* r=l1->next;
            l1->next=l2;
            l2->next=merge(r,l2->next);
            return l1;
        }
        if(l1->val < l2->val)
        {
            l1->next=merge(l1->next,l2);
            return l1;
        }        
        
       else
        {
            l2->next=merge(l1,l2->next);
            return l2;
        }        
        
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     
          if(l1==NULL && l2==NULL)
            return NULL;
        
        
        return merge(l1,l2);
        
    }
};
