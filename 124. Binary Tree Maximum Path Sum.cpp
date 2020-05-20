//Phoenix_RK


/*

https://leetcode.com/problems/binary-tree-maximum-path-sum/


Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

*/
class Solution {
public:
   int sum(TreeNode * root,int &max_so_far)
    {
        if(root==NULL)
            return 0;
           
        int ls=sum(root->left,max_so_far);
        int rs=sum(root->right,max_so_far);
        max_so_far=max(max_so_far, ls+rs+root->val);
        return max({0,root->val,ls+ root->val,rs+root->val});
     
    }
    
    int maxPathSum(TreeNode* root) {
    if(root==NULL)
        return 0;
      int max_so_far=root->val;
     int x= sum(root,max_so_far);  
      return max_so_far;
    }

};
