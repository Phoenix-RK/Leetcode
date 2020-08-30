//Phoenix_RK


/*
https://leetcode.com/problems/binary-tree-postorder-traversal/
https://www.youtube.com/watch?v=xLQKdq0Ffjg

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Follow up: Recursive solution is trivial, could you do it iteratively?

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [2,1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* r) {
       vector<int> res;
        if(r==NULL)
            return res;
       TreeNode* root=r;
        TreeNode* p;
        stack<TreeNode*> s;
        while(!s.empty() || root!=NULL)
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            } 
            else
            {
                   TreeNode* temp=s.top()->right;
                   if(temp==NULL)
                   {
                       temp=s.top();
                       res.push_back(temp->val);
                       s.pop();    
                       
                       
                       while(!s.empty() && temp==s.top()->right)
                       {
                           temp=s.top();
                           res.push_back(temp->val);
                           s.pop();
                       }
                   }
                   else
                   {
                       root=temp;
                   }
            }
         
        }
        
        return res;
    }
};
