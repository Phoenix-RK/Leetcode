//Phoenix_RK


/*


https://leetcode.com/problems/invert-binary-tree/





Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

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
    TreeNode* swap(TreeNode* root)
    {
        if(!root)
            return root;
        
        TreeNode* temp=swap(root->left);
        root->left= swap(root->right);
        root->right= temp;
        
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
     
        if(!root)
            return root;
        
      return swap(root);
        
    
    }
};
