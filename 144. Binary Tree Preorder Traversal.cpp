//Phoenix_RK

/*

https://leetcode.com/problems/binary-tree-preorder-traversal/

Modify a binary tree to get preorder traversal using right pointers only
Given a binary tree. Modify it in such a way that after modification you can have a preorder traversal of it using only the right pointers. During modification, you can use right as well as left pointers.

Examples:

Input :    10
          /   \
        8      2
      /  \    
    3     5  
Output :    10
              \
               8
                \ 
                 3
                  \
                   5
                    \
                     2
Explanation : The preorder traversal
of given binary tree is 10 8 3 5 2.

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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if(root==NULL)
            return res;
        TreeNode *head=root;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* pre=NULL;
        while(!s.empty())
        {
            TreeNode* p=s.top();
            s.pop();
            cout<<p->val<<" ";
            if(p->right)
                s.push(p->right);
            
            if(p->left)
                s.push(p->left);
            
            if(pre!=NULL)
            {
                   pre->right=p;    
                   pre->left=NULL;
            } 
            
            pre=p;     
        }       
        
        while(head)
        {
            res.push_back(head->val);
            head=head->right;
        }
        
        return res;
    }
};
