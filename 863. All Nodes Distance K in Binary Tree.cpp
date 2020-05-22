//Phoenix_RK

/*

https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int,int> seen;
void fillparent(TreeNode* parent,TreeNode *child,map<TreeNode* ,TreeNode*>&m)
{
    if(child==NULL)
      return;
    
    m[child]=parent;
    seen[child->val]=0;
    fillparent(child,child->left,m);
    fillparent(child,child->right,m);
}
 vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
{
    vector<int> res;

    map<TreeNode*,TreeNode*> m;
    fillparent(NULL,root,m);
    queue<TreeNode*> q;
    q.push(target);
   
    int level=0;
    while(!q.empty())
    {
        int s=q.size();
        while(s>0)
        {
            
            if(level==K)
            {
                TreeNode *f=q.front();
                q.pop();
                res.push_back(f->val);                
            }
            
            else
            {
                 TreeNode *f=q.front();
                 q.pop();
                 seen[f->val]=1;                
                
                if(f->left && !seen[f->left->val])
                    q.push(f->left);
                    
                if(f->right && !seen[f->right->val])
                    q.push(f->right);
                    
                if(m[f]!=NULL && !seen[m[f]->val])
                    q.push(m[f]);
            }
            s--;
        }
        
        level++;
    }
return res;
}

};
