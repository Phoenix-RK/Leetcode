//Phoenix_RK


/*
https://leetcode.com/problems/validate-binary-search-tree/

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.



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
    
    bool valid(TreeNode* root,TreeNode* l,TreeNode* r)
    {
        if(root==NULL)
            return true;
        
        if(l!=NULL && l->val>=root->val)
            return false;
        
        if(r!=NULL && r->val<=root->val)
            return false;
        
       
        return valid(root->left,l,root)&&valid(root->right,root,r);
        
       
    }
    
    bool isValidBST(TreeNode* root) {
        
        if(root==NULL || (root->left==NULL &&  root->right==NULL))
            return true;
        
        return valid(root,NULL,NULL);
    }
};
