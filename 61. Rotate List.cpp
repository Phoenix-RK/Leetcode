//Phoenix_RK
/*
https://leetcode.com/problems/rotate-list/

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

********************************************************
connect the head of the LL to the tail
make the head pointer point to new head



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
    ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL)
        return NULL;
        
    ListNode* end=head;
    int count=1;
    while(end->next!=NULL)
    {
        end=end->next;
        count++;
    }
   end->next=head;
   
    k=count-k%count;
    while(k!=1)
    {
        
            head=head->next;
             k--;
    }
    ListNode* nxt=head->next;
    head->next=NULL;
    
    return nxt;
    }
};
