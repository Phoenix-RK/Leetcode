//Phoenix_RK

/*

https://leetcode.com/problems/palindrome-linked-list/


Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false


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
    
    ListNode* reverse(ListNode* head) {
    
        ListNode* prev=NULL;
        
        while(head!=NULL)
        {
            ListNode* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;    
    
    }
    bool isPalindrome(ListNode* head) {
     
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow=reverse(slow);
        fast=head;
        
        while(slow!=NULL)
        {
            if(slow->val!=fast->val)
                return false;
            
            slow=slow->next;
            fast=fast->next;
        }
        
        return true;
    }
};
