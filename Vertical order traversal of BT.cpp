/**
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.


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
    
    
    void genVerticalOrder(TreeNode *root,int hd,int d, map<pair<int,pair<int,int>>,vector<int>> &m)
    {
        if(root==NULL)
            return;
        
        m[make_pair(hd,make_pair(hd,d))].push_back(root->val);
        //if same depth and same hd value sort the vector
        sort(m[make_pair(hd,make_pair(hd,d))].begin(),m[make_pair(hd,make_pair(hd,d))].end());
        
        genVerticalOrder(root->left,hd-1,d+1,m);
        genVerticalOrder(root->right,hd+1,d+1,m);
        
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
     
      map<pair<int,pair<int,int>>,vector<int>> m;
        m.clear();
        
        int hd=0,d=0;
        genVerticalOrder(root,hd,d,m);
       
        for(auto it=m.begin();it!=m.end();it++)
        {
            cout<<it->first.first<<" ("<<it->first.second.first<<" "<<it->first.second.second<<")"<<endl;
            for(int i=0;i<it->second.size();i++)
                cout<<it->second[i]<<" ";
            cout<<endl;
        }
        
        //group same hd value to single vector
         map<int,vector<int>> ma;
        for(auto it=m.begin();it!=m.end();it++)
        {
            
           for(int i=0;i<it->second.size();i++)
              ma[it->first.first].push_back(it->second[i]);
          
        }
        
        
        
        int j=0;
         vector<vector<int>> v(ma.size());
        
         for(auto it=ma.begin();it!=ma.end();it++)
        {
           v[j]=vector<int>(it->second.size());
            for(int i=0;i<it->second.size();i++){
                
               cout<<it->second[i]<<"s ";
                v[j][i]=it->second[i];
            }
          
             j++;
            cout<<endl;
        }
        
        
        //actual answer above
        
        return v;
    }
};
