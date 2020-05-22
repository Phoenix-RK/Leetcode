//Phoenix_RK


/*

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

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
     vector<vector<int>> res;
    vector<int> b;
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    
    void print(TreeNode* root,int h,bool flag)
    {
        if(root==NULL)
            return;
        
        if(h==1)
        {
            b.push_back(root->val);
        }
        
        if(!flag)
        {
            print(root->left,h-1,flag);
            print(root->right,h-1,flag);
        }
        else if(flag)
        {
             print(root->right,h-1,flag);
             print(root->left,h-1,flag);
        }
      
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        int h=height(root);
       
        
        cout<<h<<" ";
        bool flag=false;
        for(int i=1;i<=h;i++)
        {
            print(root,i,flag);
            
            flag=!flag;
            res.push_back(b);
            b.clear();
        }
        
        return res;    
    }
};
