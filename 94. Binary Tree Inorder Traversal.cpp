//Phoenix_RK


/*

https://leetcode.com/problems/binary-tree-inorder-traversal/

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?



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
    vector<int> inorderTraversal(TreeNode* root) {
    
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> s;
        
        while(1)
        {
            
            if(root!=NULL)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                TreeNode *p=s.top();
                s.pop();
                res.push_back(p->val);
                root=p->right;                
            }
            
            if(root==NULL && s.empty())
                break;
        }
        return res;
    }
};
