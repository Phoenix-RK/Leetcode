//Phoenix_RK


/*

https://leetcode.com/problems/delete-node-in-a-bst/




Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Follow up: Can you solve it with time complexity O(height of tree)?


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.


Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []


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
    TreeNode* minValue(TreeNode* root)
    {
        if(!root)
            return root;
        
        while(root->left)
            root=root->left;
        
        return root;
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)
            return root;
        
        if(root->val<key)
            root->right=deleteNode(root->right,key);
        
        else if(root->val>key)
            root->left=deleteNode(root->left,key);
    
        else 
        {
            if(!root->left)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;         
            }
            
            else if(!root->right)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;         
            }
            
            else
            {
                TreeNode* temp=minValue(root->right);
                
                root->val=temp->val;
                
                root->right=deleteNode(root->right,temp->val);
            }
        }
            
            
        return root;
    }
};
