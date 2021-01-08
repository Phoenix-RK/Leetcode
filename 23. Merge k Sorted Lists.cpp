//Phoenix_RK



/*

https://leetcode.com/problems/merge-k-sorted-lists/

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.

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
    
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
struct compare { 
	
bool operator()(ListNode* first,ListNode* second)
{
//first is the ele at top, second is ele to be inserted 
//ele is inserted on top only when first is greater than second
	return first->val > second->val;

}
};


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
       priority_queue<ListNode*, vector<ListNode*>, compare> pq;
       
       for(int i=0;i<lists.size();i++)
       {
           
          if(lists[i])
            pq.push(lists[i]);
       }
       
       ListNode* res=NULL,*last;
       
       while(!pq.empty())
       {
           if(res==NULL)
           {
               res=pq.top();
               if(res->next)
                pq.push(res->next);
                
               last=res;
               last->next=NULL;
           }
           else
           {
               last->next=pq.top();
               last=last->next;
              
               if(last->next)
                   pq.push(last->next);
                   
               last->next=NULL;
           }
           pq.pop();
       }
       
       return res;
        
    }
};

