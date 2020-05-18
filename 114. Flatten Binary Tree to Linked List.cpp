//Phoenix_RK

/**
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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


/*
Use Stack
​Push the root into the stack. SInce the left child has to be made the right child, first push the right child into the stack and then the left child...
​Make the top of stack the right child of current node and continue exploring the childs of current node.
​repeat this until the stack is empty.
*/


class Solution {
public:
    void flatten(TreeNode* root) {
        
        if(!root)
            return;
        
        stack<TreeNode*> s;
        s.push(root);
        /*    1->2->3->4->5->6*/
        while(!s.empty())
        {
            TreeNode* curr=s.top();
            s.pop();
            if(curr->right)
                s.push(curr->right);
            if(curr->left)
                s.push(curr->left);
            
            if(!s.empty())
                curr->right=s.top();
            
            curr->left=NULL;
        }
        
    }
};

 
    

